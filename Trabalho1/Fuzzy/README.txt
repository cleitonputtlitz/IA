												Universidade Federal da Fronteira Sul - UFFS
													      Chapec� - Santa Catarina
												       Ci�ncia da Computa��o - Noturno
											   Intelig�ncia Artificial - Adriano Sanick Padilha
											  Cleiton Puttlitz, Patrick de Bastiani e Yru� Neris

Passo 1:
	Abra o terminal (shell/cmd)
	
Passo 2:
	Compile o programa.
	> gcc main.c -Wall

Passo 3:
	Execute o programa com a seguinte linha de comando:
	Windows:
	>   nome_do_programa.exe < in.txt
	
	Linux:
	$   nome_do_programa.out < in.txt
	
O seguinte trabalho � referente a disciplina de Intelig�ncia Artificial do curso de Ci�ncia da Computa��o da UFFS, o mesmo possui como finalidade auxiliar na escolha dos alunos que ser�o deferidos na solicita��o de asjustes dos componente curriculares no curso.
O sistema utiliza a l�gica FUZZY para determinar o indice de aceita��o do aluno para poder cursar a disciplina, levando em considera��o que os alunos com maior �ndice ter�o prioridade na escolha.
O �ndice de aceita��o ser� calculado com base em tr�s fatores sendo eles Veteranice(per�odo em que o aluno esta cursando), M�dia do curso e reincid�ncia (quantidade de vezes que o aluno solicitou a mat�ria no ajuste).
Cada um desses fatores � mapeado em 3 conjuntos (Baixo, Medio e Alto) e 5 conjuntos de sa�da (Muito Baixo, Baixo, Medio, Alto e Muito Alto).
O �ndice de aceita��o � calculado atr�ves do m�todo da centr�ide.