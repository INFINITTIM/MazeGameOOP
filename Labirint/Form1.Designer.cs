namespace Labirint
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.Hp = new System.Windows.Forms.Label();
            this.Moneta = new System.Windows.Forms.Label();
            this.panel_labirint = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // Hp
            // 
            this.Hp.AutoSize = true;
            this.Hp.Font = new System.Drawing.Font("Microsoft Sans Serif", 50F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Hp.ForeColor = System.Drawing.Color.White;
            this.Hp.Location = new System.Drawing.Point(22, 9);
            this.Hp.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.Hp.Name = "Hp";
            this.Hp.Size = new System.Drawing.Size(197, 95);
            this.Hp.TabIndex = 3;
            this.Hp.Text = "Hp: ";
            // 
            // Moneta
            // 
            this.Moneta.AutoSize = true;
            this.Moneta.Font = new System.Drawing.Font("Microsoft Sans Serif", 49.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Moneta.ForeColor = System.Drawing.Color.White;
            this.Moneta.Location = new System.Drawing.Point(388, 9);
            this.Moneta.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.Moneta.Name = "Moneta";
            this.Moneta.Size = new System.Drawing.Size(309, 95);
            this.Moneta.TabIndex = 4;
            this.Moneta.Text = "Coins: ";
            this.Moneta.Click += new System.EventHandler(this.Moneta_Click);
            // 
            // panel_labirint
            // 
            this.panel_labirint.BackColor = System.Drawing.Color.Gray;
            this.panel_labirint.Location = new System.Drawing.Point(15, 116);
            this.panel_labirint.Name = "panel_labirint";
            this.panel_labirint.Size = new System.Drawing.Size(1146, 856);
            this.panel_labirint.TabIndex = 7;
            this.panel_labirint.Paint += new System.Windows.Forms.PaintEventHandler(this.panel_around_Paint);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(185, 11);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(0, 29);
            this.label1.TabIndex = 5;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Black;
            this.ClientSize = new System.Drawing.Size(1240, 984);
            this.Controls.Add(this.panel_labirint);
            this.Controls.Add(this.Moneta);
            this.Controls.Add(this.Hp);
            this.Controls.Add(this.label1);
            this.DoubleBuffered = true;
            this.ForeColor = System.Drawing.SystemColors.ActiveCaption;
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label Hp;
        private System.Windows.Forms.Label Moneta;
        private System.Windows.Forms.Panel panel_labirint;
        private System.Windows.Forms.Label label1;
    }
}