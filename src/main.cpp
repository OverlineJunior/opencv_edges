#include "opencv2/core/base.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
    // Lê imagem em tons de cinza.
    cv::Mat imgGray = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    if (imgGray.empty()) {
        std::cerr << "Erro: não foi possível carregar a imagem.\n";
        return -1;
    }

    // Gera imagem com bordas realçadas e fundo preto.
    // CV_16S é usado pois o Laplaciano pode 1. gerar valores negativos 2. e valores maiores que 255.
    // BORDER_CONSTANT expande a imagem com zeros nas bordas; aprendido em aula.
    cv::Mat edges16;
    cv::Laplacian(imgGray, edges16, CV_16S, 3, 1, 0, cv::BORDER_CONSTANT);

    // Converte para CV_8U, necessidade de cv::imshow.
    // Há a perda dos sinais negativos, que servem para indicar a direção da borda (claro -> escuro ou vice-versa).
    cv::Mat edges8;
    cv::convertScaleAbs(edges16, edges8);

    // Gera imagem similar à original, mas com as bordas realçadas.
    cv::Mat enhanced;
    cv::add(imgGray, edges8, enhanced, cv::noArray(), CV_8U);

    cv::imshow("Original (Tons de Cinza)", imgGray);
    cv::imshow("Bordas (Laplaciano)", edges8);
    cv::imshow("Bordas Realçadas", enhanced);

    cv::imwrite("images/grayscale.png", imgGray);
    cv::imwrite("images/edges.png", edges8);
    cv::imwrite("images/enhanced.png", enhanced);

    cv::waitKey(0);
    return 0;
}
