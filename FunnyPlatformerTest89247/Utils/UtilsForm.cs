using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MaterialSkin.Controls;
using MaterialSkin;
using System.IO;
using System.Security;
using System.Xml;

namespace Utils
{
    public partial class UtilsForm : MaterialForm
    {
        private readonly MaterialSkinManager materialSkinManager;
        public UtilsForm()
        {
            InitializeComponent();

            // Specifics
            materialSkinManager = MaterialSkinManager.Instance;

            materialSkinManager.EnforceBackcolorOnAllComponents = true;


            materialSkinManager.AddFormToManage(this);
            materialSkinManager.Theme = MaterialSkinManager.Themes.LIGHT;
            materialSkinManager.ColorScheme = new ColorScheme(Primary.Indigo500, Primary.Indigo700, Primary.Indigo100, Accent.Pink200, TextShade.WHITE);
            this.FormStyle = FormStyles.ActionBar_48;

        }

        private void UtilsForm_Load(object sender, EventArgs e)
        {

        }

        private void materialLabel30_Click(object sender, EventArgs e)
        {

        }

        private void openAnimationSheetBtn_Click(object sender, EventArgs e)
        {

        }
        
        private XmlDocument processImage(string filePath)
        {
            try
            {
                using (Bitmap image = new Bitmap(filePath))
                {
                    int frameCount = image.Width / (int)this.numericFrameWidth.Value;
                    this.materialMultiLineTextBox1.AppendText($"There is {frameCount} frames \n");

                    XmlDocument xmlDocument = new XmlDocument();
                    XmlElement rootElement = xmlDocument.CreateElement("AnimationSheet");
                    rootElement.SetAttribute("file", Path.GetFileName(filePath));
                    xmlDocument.AppendChild(rootElement);

                    for (int frameId = 0; frameId < frameCount; frameId++)
                    {
                        XmlElement frameElement = xmlDocument.CreateElement("Frame");
                        frameElement.SetAttribute("id", frameId.ToString());
                        frameElement.SetAttribute("x", (frameId * this.numericFrameWidth.Value).ToString());
                        frameElement.SetAttribute("y", "0");
                        frameElement.SetAttribute("width", ((int)this.numericFrameWidth.Value).ToString());
                        frameElement.SetAttribute("height", ((int)this.numericFrameHeight.Value).ToString());

                        rootElement.AppendChild(frameElement);
                    }

                    this.materialMultiLineTextBox1.AppendText(xmlDocument.OuterXml);
                    return xmlDocument;
                }
                
            }
            catch
            {
                Console.WriteLine("Error");
                return new XmlDocument();
            }
        }
        private void openAnimSheetBtn_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "PNG Files|*.png";
            openFileDialog.Title = "Select a png file";

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                string selectedFileName = openFileDialog.FileName;
                this.materialMultiLineTextBox1.AppendText(selectedFileName);

                XmlDocument doc = processImage(selectedFileName);


                this.exportAnimBtn.Click += (sendr, args) =>
                    {
                        SaveFileDialog saveFileDialog = new SaveFileDialog();
                        saveFileDialog.Filter = "XML Files|*.xml";
                        saveFileDialog.Title = "Save xml file";

                        if (saveFileDialog.ShowDialog() == DialogResult.OK)
                        {
                            doc.Save(saveFileDialog.FileName);
                        }
                    };
            }
            

        }
    }
}
