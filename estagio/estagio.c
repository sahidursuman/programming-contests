#include <stdio.h>
#define MAX_ALUNOS 1000
int main()
{
  int i, indice_melhor, n;
  int turma=1;
  struct
  {
    int codigo, media;
  } alunos[MAX_ALUNOS];
  /* le numero de alunos da primeira turma */
  scanf("%d", &n);
  while (n > 0)
    {
      /* le dados dos alunos */
      int max = -1;
      for (i = 0; i < n; i++){
         scanf("%d %d", &alunos[i].codigo, &alunos[i].media);
         if(alunos[i].media > max)
         	max = alunos[i].media;
      }
      /* procura aluno de maior media */
      printf("Turma %d\n", turma++);
      for (i = 0; i < n; i++)
         if (alunos[i].media == max)
         	printf("%d ", alunos[i].codigo);
      printf("\n\n");
      /* le numero de alunos da proxima turma */
      scanf("%d", &n);
    }
  return 0;
}
