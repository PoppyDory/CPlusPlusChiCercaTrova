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

    // trovare le righe contenenti la parola data

    ifstream fileInput("maggio.txt"); // apertura file in lettura
    string riga;
    string parola;
    int numeroRigaParolaTrovata = 0;

    

    while (parola != "exit")
    {
        cout << "inserisci parola: \n";
        cin >> parola;
        while (getline(fileInput, riga))
        {

            numeroRigaParolaTrovata++;
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
                        }
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            if (flag == true)
            {   
                
                cout << "PAROLA TROVATA IN RIGA: " << numeroRigaParolaTrovata<<" - " << riga << endl;
            }
        }
    }
    fileInput.close();
}