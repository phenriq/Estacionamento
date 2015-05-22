#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include <QTreeWidgetItem>

namespace Ui {
class Window;
}

class Window : public QDialog
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();

    void loadCarroNoPatio();
    bool pagamento(QTreeWidgetItem item);
    void setCarrosEstacionados(QString placa, QString estado, QString cidade, QString cor, QString marca, QString modelo);

private slots:
    void on_btnCadastrar_clicked();

    void on_btnSaida_clicked();

    void on_btnProcurar_clicked();

private:
    Ui::Window *ui;
    float verificaValor(float precoHora, QString dateTime);
};

#endif // WINDOW_H
