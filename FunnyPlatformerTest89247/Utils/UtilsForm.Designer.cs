namespace Utils
{
    partial class UtilsForm
    {
        /// <summary>
        /// Variable nécessaire au concepteur.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Nettoyage des ressources utilisées.
        /// </summary>
        /// <param name="disposing">true si les ressources managées doivent être supprimées ; sinon, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Code généré par le Concepteur Windows Form

        /// <summary>
        /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
        /// le contenu de cette méthode avec l'éditeur de code.
        /// </summary>
        private void InitializeComponent()
        {
            this.materialTabControl1 = new MaterialSkin.Controls.MaterialTabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.materialLabel30 = new MaterialSkin.Controls.MaterialLabel();
            this.materialCard1 = new MaterialSkin.Controls.MaterialCard();
            this.numericFrameWidth = new System.Windows.Forms.NumericUpDown();
            this.currentAnimsheetFileLabel = new MaterialSkin.Controls.MaterialLabel();
            this.openAnimSheetBtn = new MaterialSkin.Controls.MaterialButton();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.materialLabel2 = new MaterialSkin.Controls.MaterialLabel();
            this.materialLabel1 = new MaterialSkin.Controls.MaterialLabel();
            this.materialTabSelector1 = new MaterialSkin.Controls.MaterialTabSelector();
            this.frameWidthSelectLabel = new MaterialSkin.Controls.MaterialLabel();
            this.materialLabel3 = new MaterialSkin.Controls.MaterialLabel();
            this.numericFrameHeight = new System.Windows.Forms.NumericUpDown();
            this.exportAnimBtn = new MaterialSkin.Controls.MaterialButton();
            this.materialMultiLineTextBox1 = new MaterialSkin.Controls.MaterialMultiLineTextBox();
            this.materialTabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.materialCard1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericFrameWidth)).BeginInit();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericFrameHeight)).BeginInit();
            this.SuspendLayout();
            // 
            // materialTabControl1
            // 
            this.materialTabControl1.Controls.Add(this.tabPage1);
            this.materialTabControl1.Controls.Add(this.tabPage2);
            this.materialTabControl1.Depth = 0;
            this.materialTabControl1.Location = new System.Drawing.Point(6, 101);
            this.materialTabControl1.MouseState = MaterialSkin.MouseState.HOVER;
            this.materialTabControl1.Multiline = true;
            this.materialTabControl1.Name = "materialTabControl1";
            this.materialTabControl1.SelectedIndex = 0;
            this.materialTabControl1.Size = new System.Drawing.Size(788, 352);
            this.materialTabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.materialMultiLineTextBox1);
            this.tabPage1.Controls.Add(this.materialLabel30);
            this.tabPage1.Controls.Add(this.materialCard1);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(780, 326);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Animations";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // materialLabel30
            // 
            this.materialLabel30.AutoSize = true;
            this.materialLabel30.Depth = 0;
            this.materialLabel30.Font = new System.Drawing.Font("Roboto Medium", 20F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Pixel);
            this.materialLabel30.FontType = MaterialSkin.MaterialSkinManager.fontType.H6;
            this.materialLabel30.Location = new System.Drawing.Point(62, 3);
            this.materialLabel30.MouseState = MaterialSkin.MouseState.HOVER;
            this.materialLabel30.Name = "materialLabel30";
            this.materialLabel30.Size = new System.Drawing.Size(135, 24);
            this.materialLabel30.TabIndex = 66;
            this.materialLabel30.Text = "Animation2xml";
            this.materialLabel30.Click += new System.EventHandler(this.materialLabel30_Click);
            // 
            // materialCard1
            // 
            this.materialCard1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.materialCard1.Controls.Add(this.exportAnimBtn);
            this.materialCard1.Controls.Add(this.materialLabel3);
            this.materialCard1.Controls.Add(this.numericFrameHeight);
            this.materialCard1.Controls.Add(this.frameWidthSelectLabel);
            this.materialCard1.Controls.Add(this.numericFrameWidth);
            this.materialCard1.Controls.Add(this.currentAnimsheetFileLabel);
            this.materialCard1.Controls.Add(this.openAnimSheetBtn);
            this.materialCard1.Depth = 0;
            this.materialCard1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(222)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.materialCard1.Location = new System.Drawing.Point(7, 41);
            this.materialCard1.Margin = new System.Windows.Forms.Padding(14);
            this.materialCard1.MouseState = MaterialSkin.MouseState.HOVER;
            this.materialCard1.Name = "materialCard1";
            this.materialCard1.Padding = new System.Windows.Forms.Padding(14);
            this.materialCard1.Size = new System.Drawing.Size(277, 268);
            this.materialCard1.TabIndex = 0;
            // 
            // numericFrameWidth
            // 
            this.numericFrameWidth.Location = new System.Drawing.Point(126, 55);
            this.numericFrameWidth.Name = "numericFrameWidth";
            this.numericFrameWidth.Size = new System.Drawing.Size(50, 20);
            this.numericFrameWidth.TabIndex = 2;
            // 
            // currentAnimsheetFileLabel
            // 
            this.currentAnimsheetFileLabel.AutoSize = true;
            this.currentAnimsheetFileLabel.Depth = 0;
            this.currentAnimsheetFileLabel.Font = new System.Drawing.Font("Roboto", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Pixel);
            this.currentAnimsheetFileLabel.Location = new System.Drawing.Point(81, 18);
            this.currentAnimsheetFileLabel.MouseState = MaterialSkin.MouseState.HOVER;
            this.currentAnimsheetFileLabel.Name = "currentAnimsheetFileLabel";
            this.currentAnimsheetFileLabel.Size = new System.Drawing.Size(38, 19);
            this.currentAnimsheetFileLabel.TabIndex = 1;
            this.currentAnimsheetFileLabel.Text = "File : ";
            // 
            // openAnimSheetBtn
            // 
            this.openAnimSheetBtn.AutoSize = false;
            this.openAnimSheetBtn.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.openAnimSheetBtn.Density = MaterialSkin.Controls.MaterialButton.MaterialButtonDensity.Default;
            this.openAnimSheetBtn.Depth = 0;
            this.openAnimSheetBtn.HighEmphasis = true;
            this.openAnimSheetBtn.Icon = null;
            this.openAnimSheetBtn.Location = new System.Drawing.Point(3, 10);
            this.openAnimSheetBtn.Margin = new System.Windows.Forms.Padding(4, 6, 4, 6);
            this.openAnimSheetBtn.MouseState = MaterialSkin.MouseState.HOVER;
            this.openAnimSheetBtn.Name = "openAnimSheetBtn";
            this.openAnimSheetBtn.NoAccentTextColor = System.Drawing.Color.Empty;
            this.openAnimSheetBtn.Size = new System.Drawing.Size(70, 35);
            this.openAnimSheetBtn.TabIndex = 0;
            this.openAnimSheetBtn.Text = "Open";
            this.openAnimSheetBtn.Type = MaterialSkin.Controls.MaterialButton.MaterialButtonType.Contained;
            this.openAnimSheetBtn.UseAccentColor = false;
            this.openAnimSheetBtn.UseVisualStyleBackColor = true;
            this.openAnimSheetBtn.Click += new System.EventHandler(this.openAnimSheetBtn_Click);
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.materialLabel2);
            this.tabPage2.Controls.Add(this.materialLabel1);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(780, 326);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "About";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // materialLabel2
            // 
            this.materialLabel2.AutoSize = true;
            this.materialLabel2.Depth = 0;
            this.materialLabel2.Font = new System.Drawing.Font("Roboto", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Pixel);
            this.materialLabel2.Location = new System.Drawing.Point(10, 30);
            this.materialLabel2.MouseState = MaterialSkin.MouseState.HOVER;
            this.materialLabel2.Name = "materialLabel2";
            this.materialLabel2.Size = new System.Drawing.Size(416, 19);
            this.materialLabel2.TabIndex = 1;
            this.materialLabel2.Text = "A simple tool to make my life easier to make simple games";
            // 
            // materialLabel1
            // 
            this.materialLabel1.AutoSize = true;
            this.materialLabel1.Depth = 0;
            this.materialLabel1.Font = new System.Drawing.Font("Roboto", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Pixel);
            this.materialLabel1.Location = new System.Drawing.Point(7, 7);
            this.materialLabel1.MouseState = MaterialSkin.MouseState.HOVER;
            this.materialLabel1.Name = "materialLabel1";
            this.materialLabel1.Size = new System.Drawing.Size(195, 19);
            this.materialLabel1.TabIndex = 0;
            this.materialLabel1.Text = "FunnyPlatformerTools Utils";
            // 
            // materialTabSelector1
            // 
            this.materialTabSelector1.BaseTabControl = this.materialTabControl1;
            this.materialTabSelector1.CharacterCasing = MaterialSkin.Controls.MaterialTabSelector.CustomCharacterCasing.Normal;
            this.materialTabSelector1.Depth = 0;
            this.materialTabSelector1.Font = new System.Drawing.Font("Roboto", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Pixel);
            this.materialTabSelector1.Location = new System.Drawing.Point(-1, 68);
            this.materialTabSelector1.MouseState = MaterialSkin.MouseState.HOVER;
            this.materialTabSelector1.Name = "materialTabSelector1";
            this.materialTabSelector1.Size = new System.Drawing.Size(801, 27);
            this.materialTabSelector1.TabIndex = 1;
            this.materialTabSelector1.Text = "materialTabSelector1";
            // 
            // frameWidthSelectLabel
            // 
            this.frameWidthSelectLabel.AutoSize = true;
            this.frameWidthSelectLabel.Depth = 0;
            this.frameWidthSelectLabel.Font = new System.Drawing.Font("Roboto", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Pixel);
            this.frameWidthSelectLabel.Location = new System.Drawing.Point(17, 55);
            this.frameWidthSelectLabel.MouseState = MaterialSkin.MouseState.HOVER;
            this.frameWidthSelectLabel.Name = "frameWidthSelectLabel";
            this.frameWidthSelectLabel.Size = new System.Drawing.Size(91, 19);
            this.frameWidthSelectLabel.TabIndex = 3;
            this.frameWidthSelectLabel.Text = "Frame Width";
            // 
            // materialLabel3
            // 
            this.materialLabel3.AutoSize = true;
            this.materialLabel3.Depth = 0;
            this.materialLabel3.Font = new System.Drawing.Font("Roboto", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Pixel);
            this.materialLabel3.Location = new System.Drawing.Point(17, 84);
            this.materialLabel3.MouseState = MaterialSkin.MouseState.HOVER;
            this.materialLabel3.Name = "materialLabel3";
            this.materialLabel3.Size = new System.Drawing.Size(96, 19);
            this.materialLabel3.TabIndex = 5;
            this.materialLabel3.Text = "Frame Height";
            // 
            // numericFrameHeight
            // 
            this.numericFrameHeight.Location = new System.Drawing.Point(126, 84);
            this.numericFrameHeight.Name = "numericFrameHeight";
            this.numericFrameHeight.Size = new System.Drawing.Size(50, 20);
            this.numericFrameHeight.TabIndex = 4;
            // 
            // exportAnimBtn
            // 
            this.exportAnimBtn.AutoSize = false;
            this.exportAnimBtn.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.exportAnimBtn.Density = MaterialSkin.Controls.MaterialButton.MaterialButtonDensity.Default;
            this.exportAnimBtn.Depth = 0;
            this.exportAnimBtn.HighEmphasis = true;
            this.exportAnimBtn.Icon = null;
            this.exportAnimBtn.Location = new System.Drawing.Point(3, 224);
            this.exportAnimBtn.Margin = new System.Windows.Forms.Padding(4, 6, 4, 6);
            this.exportAnimBtn.MouseState = MaterialSkin.MouseState.HOVER;
            this.exportAnimBtn.Name = "exportAnimBtn";
            this.exportAnimBtn.NoAccentTextColor = System.Drawing.Color.Empty;
            this.exportAnimBtn.Size = new System.Drawing.Size(265, 35);
            this.exportAnimBtn.TabIndex = 6;
            this.exportAnimBtn.Text = "Export";
            this.exportAnimBtn.Type = MaterialSkin.Controls.MaterialButton.MaterialButtonType.Contained;
            this.exportAnimBtn.UseAccentColor = false;
            this.exportAnimBtn.UseVisualStyleBackColor = true;
            // 
            // materialMultiLineTextBox1
            // 
            this.materialMultiLineTextBox1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
            this.materialMultiLineTextBox1.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.materialMultiLineTextBox1.Depth = 0;
            this.materialMultiLineTextBox1.Font = new System.Drawing.Font("Roboto", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Pixel);
            this.materialMultiLineTextBox1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(222)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.materialMultiLineTextBox1.Location = new System.Drawing.Point(302, 41);
            this.materialMultiLineTextBox1.MouseState = MaterialSkin.MouseState.HOVER;
            this.materialMultiLineTextBox1.Name = "materialMultiLineTextBox1";
            this.materialMultiLineTextBox1.Size = new System.Drawing.Size(460, 268);
            this.materialMultiLineTextBox1.TabIndex = 67;
            this.materialMultiLineTextBox1.Text = "";
            // 
            // UtilsForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.materialTabSelector1);
            this.Controls.Add(this.materialTabControl1);
            this.Name = "UtilsForm";
            this.Text = "FunnyPlatformerTest Utilities";
            this.Load += new System.EventHandler(this.UtilsForm_Load);
            this.materialTabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.materialCard1.ResumeLayout(false);
            this.materialCard1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericFrameWidth)).EndInit();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericFrameHeight)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private MaterialSkin.Controls.MaterialTabControl materialTabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private MaterialSkin.Controls.MaterialTabSelector materialTabSelector1;
        private MaterialSkin.Controls.MaterialLabel materialLabel1;
        private MaterialSkin.Controls.MaterialLabel materialLabel2;
        private MaterialSkin.Controls.MaterialLabel materialLabel30;
        private MaterialSkin.Controls.MaterialCard materialCard1;
        private MaterialSkin.Controls.MaterialButton openAnimSheetBtn;
        private MaterialSkin.Controls.MaterialLabel currentAnimsheetFileLabel;
        private System.Windows.Forms.NumericUpDown numericFrameWidth;
        private MaterialSkin.Controls.MaterialLabel materialLabel3;
        private System.Windows.Forms.NumericUpDown numericFrameHeight;
        private MaterialSkin.Controls.MaterialLabel frameWidthSelectLabel;
        private MaterialSkin.Controls.MaterialButton exportAnimBtn;
        private MaterialSkin.Controls.MaterialMultiLineTextBox materialMultiLineTextBox1;
    }
}

