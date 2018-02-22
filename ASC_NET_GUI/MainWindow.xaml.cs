using System;
using System.Runtime.InteropServices;
using System.Windows;

namespace ASC_NET_GUI
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        [DllImport("dll\\ASC_CPP_API.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void Mb_SetStaticColor([MarshalAs(UnmanagedType.Struct)] ref ColorData resultStruct);

        public MainWindow()
        {
            InitializeComponent();
        }

        private void ButtonBase_OnClick(object sender, RoutedEventArgs e)
        {
            var colorData = new ColorData
            {
                r = Convert.ToInt32(RedValue.Text),
                g = Convert.ToInt32(GreenValue.Text),
                b = Convert.ToInt32(BlueValue.Text)
            };

            Mb_SetStaticColor(ref colorData);
        }
    }

    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi, Pack = 1)]
    public struct ColorData
    {
        public int r;
        public int g;
        public int b;
    }
}