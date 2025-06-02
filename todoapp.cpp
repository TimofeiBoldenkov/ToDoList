#include "todolist.h"
#include "./ui_todolist.h"

ToDoApp::ToDoApp(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ToDoApp)
{
    ui->setupUi(this);
}

ToDoApp::~ToDoApp()
{
    delete ui;
}

