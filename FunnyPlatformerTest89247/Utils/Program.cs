/*
 * UTILS : A simple c# project to make my life easier when making my game with raylib , this will
 * be rewritten with raygui at some point , but for now i'll make them with c# for now
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Utils
{
    internal static class Program
    {
        /// <summary>
        /// Point d'entrée principal de l'application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new UtilsForm());
        }
    }
}
