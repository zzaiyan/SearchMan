void Widget::on_pushButtonSearch_clicked()
{
    if(working)
    {
        QMessageBox::warning(this, tr("���Ե�"), tr("��ȴ���ǰ���̽���"));
        return;
    }

    ui->textBrowser->clear();

    /* �жϲ����������� */
    QString targetSentence = ui->lineEditTarget->text();
    int searchType = bool_search(targetSentence);
    targetSentence.remove(" *");
    targetSentence.remove(" +");

    /* ��Ŀ����зִ� */
    vector<string> targetWords;
    string sentence = targetSentence.toStdString();
    jieba.CutForSearch(sentence, targetWords, true);
    for(vector<string>::iterator iter = targetWords.begin(); iter != targetWords.end(); iter++){
        if(*iter == " ")
            targetWords.erase(iter);
    }

    /* ��vector����תΪ��̬���鹩��������ʹ�� */
    int szRequest = targetWords.size();
    string *request = new string [szRequest];
    for(int i=0;i<szRequest;i++)
        request[i] = targetWords[i];
    qDebug() << QString::fromStdString(request[0]);

    /* ��������������ҳ */
    ui->labelStatus->setText("���ڼ�����������...");
    int szTargetWords = targetWords.size();
    QString targets;
    for(int i=0;i<szTargetWords;i++)
    {
        qDebug() << QString::fromStdString(targetWords[i]) << ",";
        targets += QString::fromStdString(targetWords[i]);
        targets += ",";
    }
    cout << endl;
    QMessageBox::information(this, tr("�ؼ���"),
                             tr("����Ŀ��ִ���ɣ����õ��ؼ���%1��\n%2").arg(szTargetWords).arg(targets));
    int *intersection;
    int szIntersection = 0;
    int *symDifference;
    int szSymdifference = 0;
    int szUnion = RI_itsc_symdif(request, szRequest, intersection, szIntersection, symDifference, szSymdifference);
    ui->labelStatus->setText("���������������");
    QMessageBox::information(this,tr("��������"),
                             tr("��������������ɣ�����%1�����ԳƲ�%2��������%3��\n").arg(szIntersection).arg(szSymdifference).arg(szUnion));

    /* ��ʾ������� */
    ui->textBrowser->clear();
    ui->labelStatus->setText("��������...");
    ui->progressBar->setValue(0);

    switch( searchType )
    {
    case AND:
        if(szIntersection<=0)
        {
            ui->progressBar->setRange(0,100);
            ui->progressBar->setValue(100);
            ui->labelStatus->setText("�������");
            QMessageBox::information(this, tr("�������"), tr("������ɣ�δ�ҵ���ؽ��"));
            break;
        }
        ui->progressBar->setRange(0, szIntersection);
        show_results(intersection, szIntersection, targetWords);
        break;
    case OR:
        if(szUnion<=0)
        {
            ui->progressBar->setRange(0,100);
            ui->progressBar->setValue(100);
            ui->labelStatus->setText("�������");
            QMessageBox::information(this, tr("�������"), tr("������ɣ�δ�ҵ���ؽ��"));
            return;
        }
        ui->progressBar->setRange(0, szUnion);
        show_results(intersection, szIntersection, targetWords);
        show_results(symDifference, szSymdifference, targetWords);
        break;
    default: qDebug() << "Error! From bool_search";
    }

    ui->labelStatus->setText("�������");

}