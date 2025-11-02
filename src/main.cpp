#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
    // 1) Lê em tons de cinza, independentemente do formato original
    cv::Mat imgGray = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    if (imgGray.empty()) {
        std::cerr << "Erro: não foi possível carregar a imagem.\n";
        return -1;
    }

    // 2) Detecta bordas com operador que gera valores negativos
    // Laplaciano costuma dar valores < 0, então usamos CV_16S
    cv::Mat edges16;
    cv::Laplacian(imgGray, edges16, CV_16S, 3, 1, 0, cv::BORDER_DEFAULT);

    // 3) Converte para 8 bits absolutos para exibir
    cv::Mat edges8;
    cv::convertScaleAbs(edges16, edges8);

    // 4) Realça as bordas na imagem original
    // soma simples: onde tem borda, fica mais claro
    cv::Mat enhanced;
    cv::add(imgGray, edges8, enhanced, cv::noArray(), CV_8U);

    cv::imshow("Original (tons de cinza)", imgGray);
    cv::imshow("Bordas (Laplaciano)", edges8);
    cv::imshow("Imagem com bordas realcadas", enhanced);

    cv::waitKey(0);
    return 0;
}
