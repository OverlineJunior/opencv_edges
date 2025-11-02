#import "@preview/ilm:1.4.1": *

#set text(lang: "en")

#show: ilm.with(
  title: [Detecção de Bordas com _OpenCV_],
  author: "Francisco Sebastiany Junior",
	abstract: [Programa desenvolvido em _C++_ com a biblioteca _OpenCV_ para processar uma imagem em tons de cinza, aplicar o filtro Laplaciano e realçar as bordas da imagem original.],
  date: datetime.today(),
	date-format: "[day]/[month]/[year]",
	table-of-contents: none,
	chapter-pagebreak: false,
)

= Descrição do Problema

Desenvolver um programa em _C++_ que utilize a biblioteca _OpenCV_ para processar uma imagem em tons de cinza, aplicar o filtro Laplaciano e realçar as bordas da imagem original.

= Solução Proposta

== Visão Geral

+ Ler a imagem de entrada em tons de cinza usando `cv::IMREAD_GRAYSCALE`;

+ Aplicar o filtro Laplaciano para detectar bordas utilizando `cv::Laplacian`;

+ Realçar as bordas na imagem original somando a imagem de bordas à imagem original;

+ Exibir as imagens resultantes:
	+ Imagem em tons de cinza;
	+ Imagem das bordas detectadas;
	+ Iagem com as bordas realçadas.

== Características do Filtro Laplaciano

Pelo fato do filtro Laplaciano gerar (a) valores negativos e (b) valores que podem execeder 8 bits, foi necessário usar o tipo de dado `CV_16S` para armazenar os resultados do filtro, que suporta valores maiores e com sinal.

Porém, para exibir imagens, é necessário o tipo de dado `CV_8U`, que suporta apenas valores positivos de 0 a 255. Portanto, foi necessário converter a imagem resultante do filtro Laplaciano para `CV_8U` usando a função `cv::convertScaleAbs`. Vale notar que nesse processo, há a perda dos valores negativos, que indicam a direção da borda (escurecendo ou clareando).

= Resultados

A primeira imagem exibida é a original em tons de cinza, a segunda imagem mostra as bordas detectadas pelo filtro Laplaciano, e a terceira imagem apresenta a imagem original com as bordas realçadas:

#table(
	columns: 3,
	rows: 1,
	inset: 0pt,
	image("../images/grayscale.png"),
	image("../images/edges.png"),
	image("../images/enhanced.png"),
)
