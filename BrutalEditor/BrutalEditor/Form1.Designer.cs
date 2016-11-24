namespace BrutalEditor
{
    partial class BrutalEditor
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
            this.components = new System.ComponentModel.Container();
            this.preview = new System.Windows.Forms.PictureBox();
            this.LoadTileset = new System.Windows.Forms.Button();
            this.tilesetList = new System.Windows.Forms.ImageList(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.preview)).BeginInit();
            this.SuspendLayout();
            // 
            // preview
            // 
            this.preview.Location = new System.Drawing.Point(12, 297);
            this.preview.Name = "preview";
            this.preview.Size = new System.Drawing.Size(1237, 906);
            this.preview.TabIndex = 0;
            this.preview.TabStop = false;
            this.preview.MouseMove += new System.Windows.Forms.MouseEventHandler(this.preview_MouseMove);
            this.preview.Click += new System.EventHandler(this.preview_Click);
            // 
            // LoadTileset
            // 
            this.LoadTileset.Location = new System.Drawing.Point(12, 12);
            this.LoadTileset.Name = "LoadTileset";
            this.LoadTileset.Size = new System.Drawing.Size(122, 49);
            this.LoadTileset.TabIndex = 1;
            this.LoadTileset.Text = "Load Tileset";
            this.LoadTileset.UseVisualStyleBackColor = true;
            this.LoadTileset.Click += new System.EventHandler(this.LoadTileset_Click);
            // 
            // tilesetList
            // 
            this.tilesetList.ColorDepth = System.Windows.Forms.ColorDepth.Depth8Bit;
            this.tilesetList.ImageSize = new System.Drawing.Size(16, 16);
            this.tilesetList.TransparentColor = System.Drawing.Color.Transparent;
            // 
            // BrutalEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1261, 1215);
            this.Controls.Add(this.LoadTileset);
            this.Controls.Add(this.preview);
            this.Name = "BrutalEditor";
            this.Text = "Brutal Editor v0.1";
            this.Load += new System.EventHandler(this.BrutalEditor_Load);
            ((System.ComponentModel.ISupportInitialize)(this.preview)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox preview;
        private System.Windows.Forms.Button LoadTileset;
        private System.Windows.Forms.ImageList tilesetList;
    }
}

