#include <iostream>
using namespace std;

int main(){

cout << "Quadrado" << endl;

for (int i = 0; i < 9; i++)
{
  cout << "*";
}

cout << "\n";

for (int i = 0; i < 8; i++)
{
  cout << "*       * \n";
}

for (int i = 0; i < 9; i++)
{
  cout << "*";
}

cout << "\n";

cout << "Circulo oval" << endl;

cout << "   ***   \n";
cout << " *     * \n";

for (int i = 0; i < 4; i++)
{
  cout << "*       * \n";
}

cout << " *     * \n";
cout << "   ***   \n";

cout << "Seta" << endl;

cout << "  *  " << endl;
cout << " *** " << endl;
cout << "*****" << endl;

for (int i = 0; i < 6; i++)
{
  cout << "  *  \n";
}

cout << "losango" << endl;

cout << "    *     \n";
cout << "   * *     \n";
cout << "  *   *     \n";
cout << " *     *     \n";
cout << "  *   *     \n";
cout << "   * *     \n";
cout << "    *     \n";

  return 0;
}
