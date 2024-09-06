#include "startscreen.h"
#include <QDebug>

/*----------------------------------startScreen-------------------------------*/
StartScreen::StartScreen(const int &x, const int &y, QObject* parent) : QGraphicsScene(parent) {
    /*________________________iniciando a cena_______________________________*/
    // Cor de fundo           r  g    b    a
    setBackgroundBrush(QColor(2, 142, 116, 255)); // Passando uma instância temporária
    setSceneRect(0,0, x, y);

    // Botão startgame
    _startButton = new StartButton(x, y, QPixmap(":/images_design/start_button3.png"));
    addItem(_startButton);

    /*________________________iniciando a caixa de nickname__________________*/
    // A string já deve ser iniciada com as restrições de QRegularExpressionValidator
    insertNickname = new InsertString("Insira seu Nickname aqui!");
    QGraphicsProxyWidget* proxy = addWidget(insertNickname);
    proxy->setPos(frogger::X_IN_COEF*x, frogger::Y_IN_COEF*y);
    QObject::connect(_startButton, SIGNAL(clicked()), this, SLOT(verifyNickname()));
}

void StartScreen::verifyNickname(){
    if (insertNickname->hasAcceptableInput()){
        emit start(frogger::GScreen);

        /* solução menos amigável, mas que serviria para um C++ mais puro
           É necessário fazer o include recursivo da classe que detém a classe
           atual e fazer uma declaração antecipada da classe atual
        */
        // mainScreen* ptrToParent = dynamic_cast<mainScreen* >(this->parent());
        // ptrToParent->showScreen(frogger::GScreen);
    }
}


/*----------------------------------startButton-------------------------------*/
StartButton::StartButton(const int &x, const int &y, const QPixmap &pixmap, QGraphicsItem* parent)
    : QObject(), QGraphicsPixmapItem(parent) {

    setPixmap(pixmap.scaled(500, 500, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    setOffset(-250, -250);
    setPos(frogger::X_SB_COEF*x, frogger::Y_SB_COEF*y);
    QGraphicsEffect* sombra = new QGraphicsDropShadowEffect(this);
    setGraphicsEffect(sombra);

    // Enable nos eventos de hover
    setAcceptHoverEvents(true);
}

// p/ tratar o release, é necessario tratar o press event primeiro
void StartButton::mousePressEvent(QGraphicsSceneMouseEvent* event){

    if (event->button() == Qt::LeftButton){
       emit clicked();
    }
    QGraphicsPixmapItem::mousePressEvent(event);
}


void StartButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    qDebug() << "passando o mouse";
    setScale(frogger::INCREASE_SB_COEF);

    QGraphicsPixmapItem::hoverEnterEvent(event);
}

void StartButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    qDebug() << "tirando o mouse";
    setScale(frogger::DECREASE_SB_COEF);

    QGraphicsPixmapItem::hoverLeaveEvent(event);
}


/*----------------------------------textBox-----------------------------------*/
InsertString::InsertString(const QString &contents, QWidget *parent) : QLineEdit(contents, parent){

    resize(600, 50);
    // Alterando a fonte
    setFont(QFont("FreeMono", 28, QFont::DemiBold, true));
    // Restringindo espaço na caixa de texto
    QRegularExpression reg("\\S+");
    QValidator* v = new QRegularExpressionValidator(reg, this);
    setValidator(v);
}

void InsertString::mouseReleaseEvent(QMouseEvent *event){

    if (event->button() == Qt::LeftButton){
        selectAll();
        del();
    }
    QLineEdit::mouseReleaseEvent(event);
}
