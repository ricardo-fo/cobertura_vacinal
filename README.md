<h1>2º Trabalho prático da disciplina de Estrutura de Dados II</h1>
<hr>
<h3>Cobertura Vacinal</h3>
O portal do DataSUS (http://datasus.saude.gov.br/) divulga várias informações relativas saúde pública no país. Entre as informações divulgadas pelo portal, encontram-se os <strong>dados de cobertura vacinal em 5570 municípios brasileiros</strong>. O arquivo “cobertura_vacinal.csv” foi gerado a partir das informações disponíveis do portal.
Cada linha desse arquivo tem o seguinte formato:
<em>código do município;nome do município;cobertura_vacinal</em>

Implemente um programa em C que leia as informações do arquivo “cobertura_vacinal.csv” e carregue-as em um <strong>Hash Map</strong>, onde a chave é o código do município e o valor é o nome e a cobertura vacinal do município, e também em uma <strong>árvore AVL</strong> ordenada pela cobertura vacinal.
Após carregar as informações do arquivo no Hash Map e na árvore AVL, o programa deve permitir as seguintes consultas:
<ul>
	<li>Dado o código da cidade, exibir o nome do município e sua cobertura vacinal, caso o
código não exista, exibir uma mensagem de erro;</li>
	<li>Exibir as n cidades (código, nome e cobertura vacinal) com maior cobertura vacinal;</li>
	<li>Exibir as n cidades (código, nome e cobertura vacinal) com menor cobertura vacinal.</li>
</ul> 
