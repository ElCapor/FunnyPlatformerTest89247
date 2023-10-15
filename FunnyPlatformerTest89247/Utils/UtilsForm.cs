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
    }
}
