#include <stdio.h> 

// Função que retorna o índice do 
// dia para a data DD/MM/YYYY 
int numeroDoDia(int dia, int mes, int ano); 

// Função que retorna o nome do 
// mês para o número do mês dado 
char* getNomeMes(int numeroMes); 

// Função para retornar o número de dias 
// em um mês, considerando se o ano é bissexto 
int numeroDias(int numeroMes, int ano, int bissexto); 

// Função para imprimir o calendário do ano dado
void imprimirCalendario(int ano, int bissexto, int diaSemana); 

// Função principal 
int main() 
{ 
  int diaSemana;
  printf("Digite o dia da semana em que o dia 1 de janeiro cai (0 para domingo, 1 para segunda, ..., 6 para sábado): ");
  scanf("%d", &diaSemana);

  int anoBissexto;
  printf("O ano é bissexto? (1 para sim, 0 para não): ");
  scanf("%d", &anoBissexto);

  int ano = 2024; // Ano de exemplo
  imprimirCalendario(ano, anoBissexto, diaSemana);

  return 0; 
} 

int numeroDoDia(int dia, int mes, int ano) 
{ 
  // Array para armazenar os valores de t 
  static int t[] = { 0, 3, 2, 5, 0, 3, 
          5, 1, 4, 6, 2, 4 }; 
  ano -= mes < 3; 
  return (ano + ano / 4 
      - ano / 100 
      + ano / 400 
      + t[mes - 1] + dia) 
    % 7; 
} 

char* getNomeMes(int numeroMes) 
{ 
  char* mes; 

  switch (numeroMes) { 
  case 0: 
    mes = "Janeiro"; 
    break; 
  case 1: 
    mes = "Fevereiro"; 
    break; 
  case 2: 
    mes = "Março"; 
    break; 
  case 3: 
    mes = "Abril"; 
    break; 
  case 4: 
    mes = "Maio"; 
    break; 
  case 5: 
    mes = "Junho"; 
    break; 
  case 6: 
    mes = "Julho"; 
    break; 
  case 7: 
    mes = "Agosto"; 
    break; 
  case 8: 
    mes = "Setembro"; 
    break; 
  case 9: 
    mes = "Outubro"; 
    break; 
  case 10: 
    mes = "Novembro"; 
    break; 
  case 11: 
    mes = "Dezembro"; 
    break; 
  } 
  return mes; 
} 

int numeroDias(int numeroMes, int ano, int bissexto) 
{ 
  // Janeiro
  if (numeroMes == 0) 
    return (31); 

  // Fevereiro
  if (numeroMes == 1) {
    // Verificar se o ano é bissexto
    if (bissexto && ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0))
      return (29);
    else
      return (28);
  } 

  // Meses com 30 dias
  if (numeroMes == 3 || numeroMes == 5 || numeroMes == 8 || numeroMes == 10)
    return (30); 

  // Meses com 31 dias
  return (31); 
} 

void imprimirCalendario(int ano, int bissexto, int diaSemana) 
{ 
  printf("	 Calendário - %d\n\n", ano); 
  int dias; 

  // Índice do dia de 0 a 6 
  int atual = numeroDoDia(1, 1, ano); 
  int diferenca = diaSemana - atual;
  if (diferenca < 0) {
    diferenca += 7; // Ajustar para o próximo domingo
  }

  // i para iterar pelos meses 
  // j para iterar pelos dias 
  // do mês - i 
  for (int i = 0; i < 12; i++) { 
    dias = numeroDias(i, ano, bissexto); 

    // Imprimir o nome do mês atual 
    printf("\n        ***  %s  ***       \n", 
      getNomeMes(i)); 

    // Imprimir as colunas 
    printf(" Dom Seg Ter Qua Qui Sex Sáb\n"); 

    // Imprimir espaços apropriados 
    int k; 
    for (k = 0; k < diferenca; k++) 
      printf("     "); 

    for (int j = 1; j <= dias; j++) { 
      printf("%4d ", j); 

      if (++k > 6) { 
        k = 0; 
        printf("\n"); 
      } 
    } 

    if (k) 
      printf("\n"); 

    diferenca = k; 
  } 

  return; 
} 
