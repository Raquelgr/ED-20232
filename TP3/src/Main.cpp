#include <iostream>
#include <getopt.h>
#include <sys/resource.h>

#include <SegTree.hpp>

using namespace std;

int main(int argc, char* argv[]) try {
	int instantesDeTempo = 0;
	int operacoesRealizadas = 0;

	cin >> instantesDeTempo >> operacoesRealizadas;
  
  SegTree* arvoreDeSegmentacao = new SegTree(instantesDeTempo); //A criação da segTree acontece toda no construtor

  for (int i = 0; i < operacoesRealizadas; i++) {
    char operacao;
    cin >> operacao;

    if (operacao == 'u') {
      int instante = 0;
      cin >> instante;

      int p1, p2, p3, p4;
      cin >> p1 >> p2 >> p3 >> p4;

      Matriz matrizDeAtualizacao;
      matrizDeAtualizacao.m[0][0] = p1;
      matrizDeAtualizacao.m[0][1] = p2;
      matrizDeAtualizacao.m[1][0] = p3;
      matrizDeAtualizacao.m[1][1] = p4;

      arvoreDeSegmentacao->Atualiza(instante, matrizDeAtualizacao);
    } else if (operacao == 'q') {
      int nascimento = 0;
      int morte = 0;
      int x = 0;
      int y = 0;

      cin >> nascimento >> morte >> x >> y;

      Matriz matrizDoIntervalo = arvoreDeSegmentacao->Consulta(nascimento, morte);

      int morteX = 0;
      int morteY = 0;

      // Mod 100000000 para pegar os 8 dígitos significativos 
      morteX = (matrizDoIntervalo.m[0][0] * x + matrizDoIntervalo.m[0][1] * y) % 100000000; //Transformação linear no ponto X
      morteY = (matrizDoIntervalo.m[1][0] * x + matrizDoIntervalo.m[1][1] * y) % 100000000; //Transformação linear no ponto Y
      
      cout << morteX << " " << morteY << endl;
    }
  }

  delete arvoreDeSegmentacao;

	/* Contagem de tempo */
	// double utime, stime, total_time; // contagem de tempo
	// struct rusage resources;
    // int rc;

	// if((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
    //     perror("getrusage failed");
    // utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
    // stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
    // total_time = utime+stime;
	
    // cout << "User time: " << utime << " System time: " << stime << " Total time: " << total_time << endl;


  	return 0;
}  catch (const std::exception& e) {
    // "Recolhe" exceção gerada para mostrar a mensagem
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
}