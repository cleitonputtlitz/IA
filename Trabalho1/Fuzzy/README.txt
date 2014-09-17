												Universidade Federal da Fronteira Sul - UFFS
													      Chapecó - Santa Catarina
												       Ciência da Computação - Noturno
											   Inteligência Artificial - Adriano Sanick Padilha
											  Cleiton Puttlitz, Patrick de Bastiani e Yruí Neris

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
	
O seguinte trabalho é referente a disciplina de Inteligência Artificial do curso de Ciência da Computação da UFFS, o mesmo possui como finalidade auxiliar na escolha dos alunos que serão deferidos na solicitação de asjustes dos componente curriculares no curso.
O sistema utiliza a lógica FUZZY para determinar o indice de aceitação do aluno para poder cursar a disciplina, levando em consideração que os alunos com maior índice terão prioridade na escolha.
O índice de aceitação será calculado com base em três fatores sendo eles Veteranice(período em que o aluno esta cursando), Média do curso e reincidência (quantidade de vezes que o aluno solicitou a matéria no ajuste).
Cada um desses fatores é mapeado em 3 conjuntos (Baixo, Medio e Alto) e 5 conjuntos de saída (Muito Baixo, Baixo, Medio, Alto e Muito Alto).
O índice de aceitação é calculado atráves do método da centróide.