#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

bool estPremier(int nombre) {
  // On vérifie si le nombre est égal à 2 ou 3
  if (nombre == 2 || nombre == 3) {
    return true;
  }
  // On vérifie si le nombre est divisible par 2 ou 3
  if (nombre % 2 == 0 || nombre % 3 == 0) {
    return false;
  }
  // On vérifie si le nombre est divisible par un nombre impair jusqu'à sa racine carrée
  for (int i = 5; i <= sqrt(nombre); i += 2) {
    if (nombre % i == 0) {
      return false;
    }
  }
  // Si le nombre n'est divisible par aucun des nombres précédents, c'est un nombre premier
  return true;
}

void writeTableToFile(vector<int> prime_numbers, string fileName) {
  ofstream file(fileName);

  if (file.is_open()) {
    file << "<html><head><title>Résultat des nombres premiers</title></head><body><table border='1'>";
    int count = 0;
    file << "<tr>";
    for(int i = 0; i < prime_numbers.size(); i++) {
      if (estPremier(prime_numbers[i])) {
        file << "<td style='background-color: yellow;'>" << prime_numbers[i] << "</td>";
      } else {
        file << "<td>" << prime_numbers[i] << "</td>";
      }
      count++;
      if (count == 10) {
        file << "</tr><tr>";
        count = 0;
      }
    }
    while (count != 0 && count != 10) {
      file << "<td></td>";
      count++;
    }
    file << "</tr>";
    file << "</table></body></html>";

    cout << "Le fichier " << fileName << " a été créé avec succès." << endl;
    file.close();
  } else {
    cout << "Impossible d'ouvrir le fichier." << endl;
  }
}

int main() {
  int limite;
  string choice;
  vector<int> prime_number;
  cout << "Entrez un nombre : ";
  cin >> limite;
  for(int i = 0; i < limite+1; i++){
    prime_number.push_back(i);
  }
  cout << "Sur " << limite << " " << prime_number.size() << "/" << limite << " sont premiers" << endl;
  cout << "Voulez-vous les voir ?" << endl;
  cin >> choice;
  if(choice=="y"){
    // Écrire les nombres premiers dans un fichier HTML
    writeTableToFile(prime_number, "resultat.html");
  }
  return 0;
}


