using NetGL;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    /// <summary>
    /// Simple modern opengl application made with NetGL
    /// </summary>
    public partial class Form1 : Form
    {
        private NetGL.OpenGL gl;
        private float rotate;
        public Form1()
        {
            InitializeComponent();
            CheckForIllegalCrossThreadCalls = false;
            DoubleBuffered = false;
        }       

        private void loop()
        {
            //Creating the Vertex shader
            string vertexShaderCode = @"
                #version 330 core

                layout(location = 0) in vec3 inPosition;
                layout(location = 1) in vec3 inColor;

                out vec3 color;

                void main()
                {
                    gl_Position = vec4(inPosition, 1.0);
                    color = inColor;
                }
            ";

            //Creating the fragment shader
            string fragmentShaderCode = @"
                #version 330 core

                in vec3 color;
                out vec4 fragColor;

                void main()
                {
                    fragColor = vec4(color, 1.0);
                }
            ";

            //Setup netgl
            gl = new NetGL.OpenGL();
            gl.modernGL = true;
            gl.Initial(this.panel1.Handle);
            gl.ClearColor(0.0f, 0.0f, 0.0f, 0.0f);

            //Create the Vertex Shader
            int vertexShader = gl.CreateShader(OpenGL.VertexShader);
            gl.SetShaderSource(vertexShader, 1, vertexShaderCode);
            gl.CompileShader(vertexShader);

            //Creat the fragment Shader
            int fragmentShader = gl.CreateShader(OpenGL.FragmentShader);
            gl.SetShaderSource(fragmentShader, 1, fragmentShaderCode);
            gl.CompileShader(fragmentShader);

            //Create a programm out of the vertex and fragment shader
            int program = gl.CreateProgram();
            gl.AttachShader(program, vertexShader);
            gl.AttachShader(program, fragmentShader);
            gl.LinkProgram(program);
            gl.UseProgram(program);


            //Generte the vbo
            float[] verticies =
            {
                0f, 1f, -1f,
                -1f, -1f, -1f,
                1f, -1f, -1f
            };
            int vertexBuffer = gl.GenBuffer(1);
            gl.BindBuffer(OpenGL.ArrayBuffer, vertexBuffer);
            gl.BufferData(OpenGL.ArrayBuffer, verticies.Length * sizeof(float), verticies, OpenGL.StaticDraw);

            //Generate the cbo
            float[] colors =
            {
                1.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 1.0f
            };
            int colorBuffer = gl.GenBuffer(1);
            gl.BindBuffer(OpenGL.ArrayBuffer, colorBuffer);
            gl.BufferData(OpenGL.ArrayBuffer, colors.Length * sizeof(float), colors, OpenGL.StaticDraw);


            //Load the 2D ortho matrix
            gl.Ortho(-2f, 2f, -2f, 2f, -20f, 20f);
            
            while (true) {
                Thread.Sleep(60);
                gl.Clear(NetGL.OpenGL.ColorBufferBit | NetGL.OpenGL.DepthBufferBit);

                //Send the vbo to the shader
                gl.EnableVertexAttribArray(0);
                gl.BindBuffer(OpenGL.ArrayBuffer, vertexBuffer);
                gl.VertexAttribPointer(0, 3, OpenGL.Float, false, 0, 0);

                //Send the cbo to the shader
                gl.EnableVertexAttribArray(1);
                gl.BindBuffer(OpenGL.ArrayBuffer, colorBuffer);
                gl.VertexAttribPointer(1, 3, OpenGL.Float, false, 0, 0);

                //Render the Triangle
                gl.DrawArrays(OpenGL.Triangles, 0, 3);

                gl.Flush();
                rotate += 1;
                gl.SwapLayerBuffers(NetGL.OpenGL.SwapMainPlane);

                //Print if there is any error
                Console.WriteLine(gl.GetError());
            }
        }

        private void Form1_Shown(object sender, EventArgs e)
        {
            Thread renderThread = new Thread(new ThreadStart(loop));
            renderThread.Start();
        }
    }
}
