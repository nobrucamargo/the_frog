# Análise orientada a objeto
> <p><span style="color:pink">A <strong>análise</strong> orientada a objeto consiste nas duas primeiras etapas da tabela abaixo, a definição de casos de uso e a definição do domínio do problema. </span></p>
| <span style="color:red"><strong>Casos de uso </strong></span>| Domínio do problema | Diagrama de iteração | Diagrama de classes |
| ------------------------------------------------------------ | ------------------- | -------------------- | ------------------- |

## Casos de uso - The Frog

Sendo o desenvolvimento dos casos de uso a primeira etapa da análise orientada a objeto, desenvolveu-se o seguinte rascunho de funcionamento do jogo:

* O **usuário** vai *iniciar* o **jogo**;
* O **usuário** *moverá* a **rã** para *frente e para trás*;
* A **rã** poderá ser *atropelada* por **carros**;
* A **rã** poderá ser *afogada* no **rio**;
* A **rã** poderá se *equilibrar* em **troncos**;
* A **rã** e os **troncos** se *moverão*;
* Os **troncos** poderão *ser diferentes*;
* Os **troncos** poderão *ser diferentes* dependendo da **corrente**;
* A *velocidade* dos **troncos** *será diferente* em cada **corrente**;
* Os **carros** se *moverão* em *velocidades* diferentes;
* Os **carros** poderão *ser diferentes* uns dos outros;
* Os **carros** terão *velocidades diferentes* dependendo da **pista**;
* Os **carros** *serão diferentes* dependendo da **pista**.
  
Onde os substantivos, em negrito, são os candidatos a atores/objetos/classes e os verbos/características em itálico são os candidadtos à métodos e atributos dos objetos. a primeira parte do rascunho original é mostrado na figura abaixo.

<br><div align="center">
<img src="images/casos_de_uso.jpeg" width="50%">
</div>

<br>
Apartir do rascunho principal de caso de uso, mostrado acima, foi construído uma tabela formal de casos de uso, a qual pode ser vista asseguir.
<br>

| Caso de uso:        | Jogar The Frog                                                                                                     |
| :------------------ | :----------------------------------------------------------------------------------------------------------------- |
| Objetivo            | Este caso de uso descreve a lógica principal de uma partida de The Frog                                            |
| Requisitos          | - Menu de game com tabela de pontuações anteriores, opção de start game e leave game; <br>- Esquema de vida e pontuação; <br>- Jogo de atravessar todos os sapos pela rua e pelo rio até a toca; <br>- O jogo deve mostrar o level no início de cada partida; <br>- Temporizador de partida; <br>- O sapo deverá ser movido em um plano x,y; <br>- A partida terá fixa 4 faixas de trânsito, duas calçadas, um rio com 4 correntes e 6 tocas; <br>- O sapo poderá ser atropelado; <br>- O sapo poderá ser afogado <br>- As tocas serão vitória régias; <br>- Cada faixa de carro possuirá 1 tipo de carro com velocidade diferente; <br>- Duas correntes do rio serão carregando troncos, cada uma com troncos de um tamanho e velocidade prédefinida; <br>- Duas correntes possuirão tartarugas nadando no lado oposto aos troncos e cada corrente com uma velocidade; <br>- O jogodeve possuir uma tela de game over.          |
| Atores              | Jogador                                                                                                            |
| Prioridade          | Alta                                                                                                               |
| Pré-condições       | - Interface gráfica deve ser carregada; <br>- Velocidades pré-definidas; <br>- Pontuações anteriores devem ser carregadas. |
| Frequência de uso   | Alta;                                                                                                              |
| Criticalidade       | Alta (É necessário implementar obrigatoriamente?);                                                                 |
| Condição de entrada | O jogador solicita nova partida                                                                                    |
| Fluxo principal     | 
| Fluxo alternativo   |
| Pós condições       |
| Regras de negócio   |
 


<div align="center">

[Retroceder](README.md) | [Avançar](projeto.md)

</div>