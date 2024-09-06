#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Adicionando uma cena
    QGraphicsScene* gameScreen = new QGraphicsScene();
    // Criando um ítem
    QGraphicsRectItem* frogg = new QGraphicsRectItem();
    // Setando a pos. e o tamanho do ítem
    frogg->setRect(0, 0, 100, 100);
    // Adc. o ítem à cena
    gameScreen->addItem(frogg);
    // Adicionando uma visualização de uma cena
    QGraphicsView* vista1 = new QGraphicsView(gameScreen);
    /* Alternativamente, pode-se adicionar uma cena à vista pelo seguinte método:
     * vista1->setScene(gameScreen); */
    vista1->show();

    return a.exec();
}
