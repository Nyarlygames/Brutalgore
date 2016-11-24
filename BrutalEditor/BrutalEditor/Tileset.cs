using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows.Forms;
using System.Drawing;
using System.Drawing.Drawing2D;

namespace BrutalEditor
{
    class Tileset
    {
        public List<Image> bitmapList = new List<Image>();
        public Panel tilePanel = new Panel();
        public List<PictureBox> tilespic = new List<PictureBox>();
        public Image tilecursor;

        public Tileset()
        {
        }
        public Tileset(string tilefolder)
        {

            if (tilefolder == "")
            {
                bitmapList.Add(Image.FromFile("tilesets\\default\\0.png"));
                bitmapList.Add(Image.FromFile("tilesets\\default\\1.png"));
                bitmapList.Add(Image.FromFile("tilesets\\default\\2.png"));
                bitmapList.Add(Image.FromFile("tilesets\\default\\3.png"));                
                bitmapList.Add(Image.FromFile("tilesets\\default\\4.png"));
                bitmapList.Add(Image.FromFile("tilesets\\default\\5.png"));
                bitmapList.Add(Image.FromFile("tilesets\\default\\6.png"));
                bitmapList.Add(Image.FromFile("tilesets\\default\\7.png"));
                bitmapList.Add(Image.FromFile("tilesets\\default\\8.png"));
                bitmapList.Add(Image.FromFile("tilesets\\default\\9.png"));
                bitmapList.Add(Image.FromFile("tilesets\\default\\10.png"));

                tilePanel.Location = new Point(10, 42);
                tilePanel.Size = new Size(820, 140);
                tilePanel.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
                for (int x = 0; x < bitmapList.Count; x++){
                    bitmapList[x] = resizeImage(bitmapList[x], 50, 50);
                    PictureBox temp = new PictureBox();
                    temp.Location = new System.Drawing.Point((x*55), 5);
                    temp.Name = "tile" + x.ToString();
                    temp.Size = new System.Drawing.Size(bitmapList[x].Size.Width, bitmapList[x].Size.Height);
                    temp.TabIndex = 0;
                    temp.TabStop = false;
                    temp.Image = bitmapList[x];
                    temp.Click += new System.EventHandler(this.TileBox_Click);
                    tilespic.Add(temp);
                    tilePanel.Controls.Add(temp);
                }

                //for later : temp.Dispose();
            }
        }
        public static Image resizeImage(Image image, int new_height, int new_width)
        {
            Bitmap new_image = new Bitmap(new_width, new_height);
            Graphics g = Graphics.FromImage((Image)new_image);
            g.InterpolationMode = InterpolationMode.High;
            g.DrawImage(image, 0, 0, new_width, new_height);
            return new_image;
        }
        private void TileBox_Click(object sender, EventArgs e)
        {
            var picbox = sender as PictureBox;
            tilecursor = picbox.Image;
        }
    }
}
