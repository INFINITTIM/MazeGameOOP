using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Labirint
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            this.KeyPreview = true;
            this.KeyDown += new KeyEventHandler(FormKeyDown);
        }

        private void FormKeyDown(object sender, KeyEventArgs e)
        {
            int keyCode = (int)e.KeyCode;
            try
            {
                controller.step(keyCode);
            }
            catch (HeroHPNet)
            {
                MessageBox.Show("Вы проиграли!", "Поражение!", MessageBoxButtons.OK, MessageBoxIcon.Information);
                this.Close();
            }
            catch (WallEx)
            {
                hp_count.evnt_net(g);
            }
            catch (WinnerHero)
            {
                MessageBox.Show("Вы выиграли", "Ура", MessageBoxButtons.OK, MessageBoxIcon.Information);
                this.Close();
            }
        }

        public ModelNet g;
        private ControllerNet controller;
        public LabirintAroundNet labirint_view;
        public MonetaNet moneta_count;
        public HPNet hp_count;

        private void Form1_Load(object sender, EventArgs e)
        {
            g = new ModelNet();
            controller = new ControllerNet(g);

            labirint_view=new LabirintAroundNet(panel_labirint);
            g.addObserver(labirint_view);

            moneta_count = new MonetaNet(Moneta);
            g.addObserver(moneta_count);

            hp_count = new HPNet(Hp);
            g.addObserver(hp_count);
        }

        private void panel_around_Paint(object sender, PaintEventArgs e)
        {
            g.update();
        }

        private void Moneta_Click(object sender, EventArgs e)
        {

        }
    }
}
