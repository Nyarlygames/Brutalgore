using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace BrutalEditor
{
    public partial class BrutalEditor : Form
    {
        string tilesetpath = "";
        Tileset tileset;
        PictureBox cursortile;
        int mouseX = 0;
        int mouseY = 0;

        public BrutalEditor()
        {
            InitializeComponent();
        }

        private void BrutalEditor_Load(object sender, EventArgs e)
        {
            Bitmap previewbit = new Bitmap(preview.Size.Width, preview.Size.Height);
            for (int i = 0; i < previewbit.Size.Width; i++) {
                for (int y = 0; y < previewbit.Size.Height; y++)
                {
                    previewbit.SetPixel(i, y, Color.Orange);
                }
            }
            preview.Image = previewbit;
        }

        private void LoadTileset_Click(object sender, EventArgs e)
        {
            if (cursortile != null)
                cursortile.Dispose();
            tileset = new Tileset(tilesetpath);
            this.Controls.Add(tileset.tilePanel);
            cursortile = new PictureBox();
            this.Controls.Add(cursortile);
        }

        private void preview_MouseMove(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            // Update the mouse path that is drawn onto the Panel.
            var picbox = sender as PictureBox;
            if ((tileset != null) && (tileset.tilecursor != null))
            {
                mouseX = e.X + picbox.Location.X - tileset.tilecursor.Size.Width - 5;
                mouseY = e.Y + picbox.Location.Y - tileset.tilecursor.Size.Height - 5;
                cursortile.Location = new System.Drawing.Point(e.X + picbox.Location.X - tileset.tilecursor.Size.Width - 5, e.Y + picbox.Location.Y - tileset.tilecursor.Size.Height - 5);
                cursortile.Name = "cursor";
                cursortile.Size = new System.Drawing.Size(tileset.tilecursor.Size.Width, tileset.tilecursor.Size.Height);
                cursortile.TabIndex = 0;
                cursortile.TabStop = false;
                cursortile.Image = tileset.tilecursor;
                cursortile.BringToFront();
            }
        }
        private void preview_Click(object sender, EventArgs e)
        {
            var mouse = e as MouseEventArgs;
            // Update the mouse path that is drawn onto the Panel.
            var picbox = sender as PictureBox;
            int posX = mouse.X - tileset.tilecursor.Size.Width - 5;
            int posY = mouse.Y - tileset.tilecursor.Size.Height - 5;
            Console.Write("mouse : " + mouse.X + "/" + mouse.Y + " | picbox : " + picbox.Location.X + "/" + picbox.Location.Y + " | cursor : " + tileset.tilecursor.Size.Width + "/" + tileset.tilecursor.Size.Height);
            Graphics dest = Graphics.FromImage(picbox.Image);
            dest.DrawImage(cursortile.Image, posX, posY, cursortile.Image.Size.Width, cursortile.Image.Size.Height);
            dest.Save();
        }
    }
}
