#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRandomGenerator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    top=new QLabel(this);
    top->setPixmap(QPixmap(":/res/images/0.jpg"));
    top->setFixedSize(40, 40);
    top->setScaledContents(true);


    // Rastgele başlangıç konumu
    int startX = QRandomGenerator::global()->bounded(width() - 40);
    int startY = QRandomGenerator::global()->bounded(height() / 2);
    top->move(startX, startY);

    // Hareket yönleri
    dx = 5;
    dy = 5;

    score = 0;
    ui->pushButton->setText("Skor: 0");

    // Timer
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateGame);
    timer->start(40);

    // Fare hareketlerini yakalamak için
    setMouseTracking(true);
    ui->centralwidget->setMouseTracking(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateGame()
{
    // Topun yeni konumu
    int x = top->x() + dx;
    int y = top->y() + dy;

    // --- KENARLARA ÇARPMA ---
    if (x <= 0 || x + top->width() >= width())
        dx = -dx;

    if (y <= 0)
        dy = -dy;

    // --- PLATFORM (BUTON) ÇARPMASI ---
    QRect topRect(x, y, top->width(), top->height());
    QRect platformRect(ui->pushButton->x(), ui->pushButton->y(),
                       ui->pushButton->width(), ui->pushButton->height());

    if (topRect.intersects(platformRect))
    {
        dy = -dy;  // Yukarı seker
        score++;
        ui->pushButton->setText("Skor: " + QString::number(score));
    }

    // --- PLATFORMU ISKALAMA (OYUN BİTER) ---
    if (y + top->height() >= height())
    {
        timer->stop();
        top->setPixmap(QPixmap(":/res/images/patlamis.png"));
        top->setFixedSize(40, 40);
        top->setScaledContents(true);
        return;
    }

    // Yeni konuma taşı
    top->move(x, y);
}

// Pencere boyutu değişirse her şey otomatik uyum sağlar
void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    // Platformu her zaman en aşağıda tut
    ui->pushButton->move((width() - ui->pushButton->width()) / 2,
                          height() - ui->pushButton->height() - 10);
}


// Fare ile platformu hareket ettir
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    int mouseX = event->x(); // fare X koordinatı
    int btnWidth = ui->pushButton->width();
    int newX = mouseX - btnWidth / 2; // fareyi ortala

    // Sınır kontrolü
    if (newX < 0) newX = 0;
    if (newX + btnWidth > width()) newX = width() - btnWidth;

    ui->pushButton->move(newX, ui->pushButton->y());
}
