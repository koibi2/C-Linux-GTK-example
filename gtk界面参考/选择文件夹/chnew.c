#include <gtk/gtk.h>
void print_filename(GtkWidget *file)
{
    GtkWidget *dialog;
    gchar *filename;
    //将刚才赋的值传给filename变量
    filename=gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file));
    //（刚才未销毁，而是将指针传入）销毁“选择目录”对话框
    gtk_widget_destroy(file);
    //新建新窗口dialog。打印filename的值。
    dialog=gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,filename);
    //？？
    gtk_dialog_run(GTK_DIALOG(dialog));
    //销毁新窗口dialog。
    gtk_widget_destroy(dialog);
}
void select_file(GtkWidget *widget,gpointer data)//点击主界面的按钮后，执行。
{
    GtkWidget *file; 
    int file_return;
    //创建选择目录对话框  //新参数（只打开文件夹GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER）打开文件：GTK_FILE_CHOOSER_ACTION_OPEN
    file=file=gtk_file_chooser_dialog_new("SelectFile",NULL,GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,GTK_STOCK_OK,GTK_RESPONSE_ACCEPT,NULL);    //若（点击确认按钮）？？
    if(gtk_dialog_run(GTK_DIALOG(file))==GTK_RESPONSE_ACCEPT)
        print_filename(file);//调用print_filename函数。将“选择目录”对话框的指针传入
    else//若直接点“取消”按钮
        gtk_widget_destroy(file);//销毁“选择目录”对话框
}
int main(int argc,char **argv)
{
    GtkWidget *win;
    GtkWidget *button;
    gtk_init(&argc,&argv);
    win=gtk_window_new(GTK_WINDOW_TOPLEVEL);//创建主界面
    gtk_window_set_title(GTK_WINDOW(win),"FileDialog");//设置主界面标题
    gtk_window_set_position(GTK_WINDOW(win),GTK_WIN_POS_CENTER);//主界面位置
    //关闭时销毁窗口
    g_signal_connect(G_OBJECT(win),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    //主界面的点击按钮
    button=gtk_button_new_with_label("Click Me");
    gtk_container_add(GTK_CONTAINER(win),button);//将按钮添加至布局
    //设置回调函数（点击按钮，执行select_file() ）
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(select_file),NULL);
    gtk_widget_show_all(win);//显示主布局
    gtk_main();
    return 0;
}
