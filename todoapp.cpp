#include "todoapp.h"
#include "./ui_todoapp.h"

ToDoApp::ToDoApp(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ToDoApp)
{
    ui->setupUi(this);
}

ToDoApp::~ToDoApp()
{
    delete ui;
}

