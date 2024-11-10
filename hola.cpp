#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Función para ingresar las estadísticas de cada equipo en prueba.txt
void ingresarEstadisticas(const std::string& year) {
    std::ofstream prueba("prueba.txt");

    if (!prueba.is_open()) {
        std::cerr << "No se pudo abrir prueba.txt.\n";
        return;
    }

    std::vector<std::string> equipos = {
        "49ers", "bears", "bengals", "bills", "broncos", "browns", "buccaneers",
        "cardinals", "chargers", "chiefs", "colts", "cowboys", "dolphins", "eagles",
        "falcons", "giants", "jaguars", "jets", "lions", "packers", "panthers",
        "patriots", "raiders", "rams", "ravens", "commanders", "saints", "seahawks",
        "steelers", "texans", "titans", "vikings"
    };

    int puntos, victorias, yardasTotales, perdidas;

    for (const auto& equipo : equipos) {
        std::cout << "Ingrese las estadísticas para el equipo " << equipo << ":\n";
        std::cout << "Puntos anotados: ";
        std::cin >> puntos;
        std::cout << "Victorias: ";
        std::cin >> victorias;
        std::cout << "Yardas totales: ";
        std::cin >> yardasTotales;
        std::cout << "Pérdidas de balón: ";
        std::cin >> perdidas;

        prueba << year << "," << equipo << "," << puntos << "," << victorias << ","
               << yardasTotales << "," << perdidas << "\n";
    }

    prueba.close();
    std::cout << "Estadísticas ingresadas en prueba.txt.\n";
}

// Función para transferir datos de prueba.txt a estadisticas_nfl.txt con un salto de línea al principio
void transferirDatos() {
    std::ifstream prueba("prueba.txt");
    std::ofstream archivoPrincipal("estadisticas.txt", std::ios::app);

    if (!prueba.is_open() || !archivoPrincipal.is_open()) {
        std::cerr << "No se pudo abrir prueba.txt o estadisticas_nfl.txt.\n";
        return;
    }

    // Escribimos dos saltos de línea al principio del archivo solo una vez.
    archivoPrincipal << "\n\n";

    std::string linea;
    while (getline(prueba, linea)) {
        archivoPrincipal << linea << "\n";  // Solo un salto de línea entre cada registro
    }

    prueba.close();
    archivoPrincipal.close();
    std::cout << "Datos transferidos de prueba.txt a estadisticas_nfl.txt.\n";
}

int main() {
    std::string year;
    std::cout << "Ingrese el año para las estadísticas: ";
    std::cin >> year;

    ingresarEstadisticas(year);
    transferirDatos();

    return 0;
}
