using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MicroContrl
{
    public partial class Frame : Form
    {
        public Frame()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            String[] puertos = System.IO.Ports.SerialPort.GetPortNames();
            cbPuertos.DataSource = puertos;
            CheckForIllegalCrossThreadCalls = false;
        }
       
        private void botonDesconectar_Click(object sender, EventArgs e)
        {
            if (puertoSerial.IsOpen)
            {
                puertoSerial.Close();
                MessageBox.Show("Puerto CERRADO");

                boton_pt1.Enabled = false;
                boton_pt2.Enabled = false;
                boton_pt3.Enabled = false;
                boton_pt4.Enabled = false;
                botonAutomatico.Enabled = false;
                botonManual.Enabled = false;
            }
        }

        private void botonConectar_Click(object sender, EventArgs e)
        {
            string nombrepuerto = cbPuertos.SelectedItem.ToString();
            

            if (!puertoSerial.IsOpen)
            {
                puertoSerial.PortName = nombrepuerto;
                puertoSerial.Open();
                MessageBox.Show("Puerto " + nombrepuerto + " abierto");
                botonAutomatico.Enabled = true;
                botonManual.Enabled = true;


            }
        }

        private void botonAutomatico_Click(object sender, EventArgs e)
        {
            if (puertoSerial.IsOpen)
            {
                puertoSerial.WriteLine("A");
                boton_pt1.Enabled = false;
                boton_pt2.Enabled = false;
                boton_pt3.Enabled = false;
                boton_pt4.Enabled = false;
                botonManual.Enabled = true;
                tbSerial.AppendText(System.Environment.NewLine);
                tbSerial.AppendText(System.Environment.NewLine);
            }
            
        }

        private void botonManual_Click(object sender, EventArgs e)
        {         
            if (puertoSerial.IsOpen)
            {
                puertoSerial.WriteLine("M");
                boton_pt1.Enabled = true;
                boton_pt2.Enabled = true;
                boton_pt3.Enabled = true;
                boton_pt4.Enabled = true;
                botonManual.Enabled = false;
                tbSerial.AppendText(System.Environment.NewLine);
                tbSerial.AppendText(System.Environment.NewLine);
            }

        }

        private void puertoSerial_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            if (puertoSerial.IsOpen)
            {
                try {
                    string recibido = puertoSerial.ReadLine();
                    tbSerial.AppendText(recibido);
                    tbSerial.AppendText(System.Environment.NewLine);

                } catch (Exception ) {
                    
                
                }

                

            }
        }

        private void boton_pt1_Click(object sender, EventArgs e)
        {
            
            if (puertoSerial.IsOpen)
            {
                puertoSerial.WriteLine("1");
            }
        }

        private void boton_pt2_Click(object sender, EventArgs e)
        {
            if (puertoSerial.IsOpen)
            {
                puertoSerial.WriteLine("2");
            }
        }

        private void boton_pt3_Click(object sender, EventArgs e)
        {
            if (puertoSerial.IsOpen)
            {
                puertoSerial.WriteLine("3");
            }
        }

        private void boton_pt4_Click(object sender, EventArgs e)
        {
            if (puertoSerial.IsOpen)
            {
                puertoSerial.WriteLine("4");
            }
        }
    }
}
