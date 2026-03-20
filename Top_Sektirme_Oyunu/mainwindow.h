#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>

#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


protected:
    void resizeEvent(QResizeEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private slots:
    void updateGame();


private:
    Ui::MainWindow *ui;
    QLabel *top;       // Top QLabel'i
    QTimer *timer;     // Oyun timer'ı
    int dx;            // Topun yatay hareket yönü
    int dy;            // Topun dikey hareket yönü
    int score;         // Skor
};
#endif // MAINWINDOW_H
