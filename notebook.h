#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QList>
#include <QWidget>
#include "notebookbutton.h"
#include "notebookpage.h"
#include "notebooktab.h"

class Notebook : public QWidget
{
    Q_OBJECT

public:
    Notebook(QWidget *parent);

    NotebookPage *addPage();

    enum HighlightType { none, highlighted, newMessage };

    void select(NotebookPage *page);
    void performLayout();

protected:
    void resizeEvent(QResizeEvent *);

    void settingsButtonMouseReleased(QMouseEvent *event);

public slots:
    void settingsButtonClicked();

private:
    QList<NotebookPage *> pages;

    NotebookButton addButton;
    NotebookButton settingsButton;
    NotebookButton userButton;

    NotebookPage *selected = nullptr;
};

#endif  // NOTEBOOK_H