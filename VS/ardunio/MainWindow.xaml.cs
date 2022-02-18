using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO.Ports;

namespace ardunio
{
    /// <summary>
    /// Interaktionslogik für MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        SerialPort myPort;
        public MainWindow()
        {

            InitializeComponent();
            ///////////////////Serielle Verbindung aufbauen/////////////////
            myPort = new SerialPort();
            myPort.PortName = "com3";  //richtigen COMPort auswählen anpassen
            myPort.BaudRate = 9600;
            myPort.ReadTimeout = 500;
            myPort.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);  //Event registieren
            myPort.Open();
            MessageBox.Show("Arduino erkannt!");
            //////////////////Ende/////////////////////////////////////////

        }

        private void Button_STOP(object sender, RoutedEventArgs e)
        {          
            myPort.Write("STOP"); //sende STOPsignal
        }

        private void Button_Langsam(object sender, RoutedEventArgs e)
        {
            myPort.Write("langsam"); //sende LANGSAMsignal
        }

        private void Button_Mittel(object sender, RoutedEventArgs e)
        {
            myPort.Write("mittel"); //sende MITTELsignal
        }

        private void Button_Schnell(object sender, RoutedEventArgs e)
        {
            myPort.Write("schnell"); //sende SCHNELLsignal
        }

        private static void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            SerialPort sp = (SerialPort)sender;   //Zugriff auf auslösenden Serial Port
            string daten = sp.ReadLine();         //Datenstrom einlesen
            MessageBox.Show("Status: " + daten);
            /*if (this.label_status.CheckAccess())
            {
                this.label_status.Content = "Status: " + daten;     //in Label ausgeben
            }
            else
            {

            }*/
        }




    }






}
