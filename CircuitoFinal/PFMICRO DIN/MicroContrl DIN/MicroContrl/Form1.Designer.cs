namespace MicroContrl
{
    partial class Frame
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Frame));
            this.botonConectar = new System.Windows.Forms.Button();
            this.botonDesconectar = new System.Windows.Forms.Button();
            this.cbPuertos = new System.Windows.Forms.ComboBox();
            this.botonAutomatico = new System.Windows.Forms.Button();
            this.botonManual = new System.Windows.Forms.Button();
            this.boton_pt1 = new System.Windows.Forms.Button();
            this.boton_pt4 = new System.Windows.Forms.Button();
            this.boton_pt2 = new System.Windows.Forms.Button();
            this.boton_pt3 = new System.Windows.Forms.Button();
            this.tbSerial = new System.Windows.Forms.TextBox();
            this.puertoSerial = new System.IO.Ports.SerialPort(this.components);
            this.SuspendLayout();
            // 
            // botonConectar
            // 
            this.botonConectar.Location = new System.Drawing.Point(12, 35);
            this.botonConectar.Name = "botonConectar";
            this.botonConectar.Size = new System.Drawing.Size(75, 23);
            this.botonConectar.TabIndex = 0;
            this.botonConectar.Text = "Conectar";
            this.botonConectar.UseVisualStyleBackColor = true;
            this.botonConectar.Click += new System.EventHandler(this.botonConectar_Click);
            // 
            // botonDesconectar
            // 
            this.botonDesconectar.Location = new System.Drawing.Point(93, 35);
            this.botonDesconectar.Name = "botonDesconectar";
            this.botonDesconectar.Size = new System.Drawing.Size(85, 23);
            this.botonDesconectar.TabIndex = 1;
            this.botonDesconectar.Text = "Desconectar";
            this.botonDesconectar.UseVisualStyleBackColor = true;
            this.botonDesconectar.Click += new System.EventHandler(this.botonDesconectar_Click);
            // 
            // cbPuertos
            // 
            this.cbPuertos.FormattingEnabled = true;
            this.cbPuertos.Location = new System.Drawing.Point(184, 37);
            this.cbPuertos.Name = "cbPuertos";
            this.cbPuertos.Size = new System.Drawing.Size(128, 21);
            this.cbPuertos.TabIndex = 3;
            // 
            // botonAutomatico
            // 
            this.botonAutomatico.Enabled = false;
            this.botonAutomatico.Location = new System.Drawing.Point(31, 86);
            this.botonAutomatico.Name = "botonAutomatico";
            this.botonAutomatico.Size = new System.Drawing.Size(95, 23);
            this.botonAutomatico.TabIndex = 4;
            this.botonAutomatico.Text = "Modo Auto.";
            this.botonAutomatico.UseVisualStyleBackColor = true;
            this.botonAutomatico.Click += new System.EventHandler(this.botonAutomatico_Click);
            // 
            // botonManual
            // 
            this.botonManual.Enabled = false;
            this.botonManual.Location = new System.Drawing.Point(184, 86);
            this.botonManual.Name = "botonManual";
            this.botonManual.Size = new System.Drawing.Size(95, 23);
            this.botonManual.TabIndex = 5;
            this.botonManual.Text = "Modo Manual";
            this.botonManual.UseVisualStyleBackColor = true;
            this.botonManual.Click += new System.EventHandler(this.botonManual_Click);
            // 
            // boton_pt1
            // 
            this.boton_pt1.Enabled = false;
            this.boton_pt1.Location = new System.Drawing.Point(57, 133);
            this.boton_pt1.Name = "boton_pt1";
            this.boton_pt1.Size = new System.Drawing.Size(95, 23);
            this.boton_pt1.TabIndex = 6;
            this.boton_pt1.Text = "Apagar todo";
            this.boton_pt1.UseVisualStyleBackColor = true;
            this.boton_pt1.Click += new System.EventHandler(this.boton_pt1_Click);
            // 
            // boton_pt4
            // 
            this.boton_pt4.Enabled = false;
            this.boton_pt4.Location = new System.Drawing.Point(57, 162);
            this.boton_pt4.Name = "boton_pt4";
            this.boton_pt4.Size = new System.Drawing.Size(95, 23);
            this.boton_pt4.TabIndex = 7;
            this.boton_pt4.Text = "Encender todo";
            this.boton_pt4.UseVisualStyleBackColor = true;
            this.boton_pt4.Click += new System.EventHandler(this.boton_pt4_Click);
            // 
            // boton_pt2
            // 
            this.boton_pt2.Enabled = false;
            this.boton_pt2.Location = new System.Drawing.Point(153, 134);
            this.boton_pt2.Name = "boton_pt2";
            this.boton_pt2.Size = new System.Drawing.Size(98, 22);
            this.boton_pt2.TabIndex = 8;
            this.boton_pt2.Text = "Solo V1";
            this.boton_pt2.UseVisualStyleBackColor = true;
            this.boton_pt2.Click += new System.EventHandler(this.boton_pt2_Click);
            // 
            // boton_pt3
            // 
            this.boton_pt3.Enabled = false;
            this.boton_pt3.Location = new System.Drawing.Point(153, 162);
            this.boton_pt3.Name = "boton_pt3";
            this.boton_pt3.Size = new System.Drawing.Size(98, 23);
            this.boton_pt3.TabIndex = 9;
            this.boton_pt3.Text = "Solo V2";
            this.boton_pt3.UseVisualStyleBackColor = true;
            this.boton_pt3.Click += new System.EventHandler(this.boton_pt3_Click);
            // 
            // tbSerial
            // 
            this.tbSerial.Location = new System.Drawing.Point(12, 208);
            this.tbSerial.Multiline = true;
            this.tbSerial.Name = "tbSerial";
            this.tbSerial.ReadOnly = true;
            this.tbSerial.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.tbSerial.Size = new System.Drawing.Size(300, 132);
            this.tbSerial.TabIndex = 10;
            // 
            // puertoSerial
            // 
            this.puertoSerial.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.puertoSerial_DataReceived);
            // 
            // Frame
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(321, 349);
            this.Controls.Add(this.tbSerial);
            this.Controls.Add(this.boton_pt3);
            this.Controls.Add(this.boton_pt2);
            this.Controls.Add(this.boton_pt4);
            this.Controls.Add(this.boton_pt1);
            this.Controls.Add(this.botonManual);
            this.Controls.Add(this.botonAutomatico);
            this.Controls.Add(this.cbPuertos);
            this.Controls.Add(this.botonDesconectar);
            this.Controls.Add(this.botonConectar);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Frame";
            this.Text = "Ventilación";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button botonConectar;
        private System.Windows.Forms.Button botonDesconectar;
        private System.Windows.Forms.ComboBox cbPuertos;
        private System.Windows.Forms.Button botonAutomatico;
        private System.Windows.Forms.Button botonManual;
        private System.Windows.Forms.Button boton_pt1;
        private System.Windows.Forms.Button boton_pt4;
        private System.Windows.Forms.Button boton_pt2;
        private System.Windows.Forms.Button boton_pt3;
        private System.Windows.Forms.TextBox tbSerial;
        private System.IO.Ports.SerialPort puertoSerial;
    }
}

