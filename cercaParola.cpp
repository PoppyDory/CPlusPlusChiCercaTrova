// scrivi un programma che rimanga aperto finchè l'utente non digita exit
// il programma chiede di cercare una parola nel 5 Maggio
// output: versetti con i numeri di riga in cui appare la parola cercata
// chiede la successiva parola a meno che non si inserisce exit
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{

    string riga;
    string parola;
    string strofa;
    int numeroRigaParolaTrovata = 0;
    int trovato;

    while (parola != "exit")
    {
        
        cout << "inserisci parola: \n";
        cin >> parola;
        ifstream fileInput("maggio.txt"); // apro il file
        strofa = "";
        numeroRigaParolaTrovata = 0;
        while (getline(fileInput, riga))
        {
            numeroRigaParolaTrovata++;
            if (riga != "")
            {
               strofa += to_string(numeroRigaParolaTrovata)+" - "+riga + "\n";
            }
            else
            {
                strofa = "";
            }
            bool flag = false;                      // SE TROVO LA PAROLA IMPOSTO A TRUE
            for (int i = 0; i < riga.length(); i++) // for tutta riga
            {

                for (int j = 0; j < parola.length(); j++) // for tutta parola
                {

                    if (riga[i] == parola[j]) // se le lettere sono uguali
                    {
                        if (j == parola.length() - 1) // se le lettere sono uguali E sono all'ultima lettera della parola
                        {
                            flag = true;
                            trovato=numeroRigaParolaTrovata;
                            cout <<"La strofa in cui ho trovato la parola e': "<< endl<<strofa;
                            while (getline(fileInput, riga))
                            {
                                numeroRigaParolaTrovata++;
                                if (riga == "")
                                {
                                    break;
                                }
                                else
                                {
                                    cout<< numeroRigaParolaTrovata<<" - "<<riga << "\n";
                                }
                                
                            }
                                                     
                        }
                         
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            if (flag)
            {
                cout << "PAROLA TROVATA IN RIGA: " << trovato << endl << "---------------"<<endl;
            }
        }
        fileInput.close();
    }
}