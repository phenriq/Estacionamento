#ifndef CADASTRARMARCA_H
#define CADASTRARMARCA_H

#include <QDialog>

namespace Ui {
class cadastrarMarca;
}

class cadastrarMarca : public QDialog
{
    Q_OBJECT

public:
    explicit cadastrarMarca(QWidget *parent = 0);
    ~cadastrarMarca();

private slots:
    void on_pushButton_clicked();

private:
    Ui::cadastrarMarca *ui;
};

#endif // CADASTRARMARCA_H
