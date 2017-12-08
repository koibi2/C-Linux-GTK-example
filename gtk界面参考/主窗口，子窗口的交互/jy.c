#include <gtk/gtk.h>
GtkWidget *window_test=NULL;
GtkWidget *label=NULL;
const gchar *text=NULL;
GtkWidget *entry=NULL;
GtkWidget *shuru;  
void change_label_text(GtkWidget *widget,gpointer data)
{
    text=gtk_editable_get_chars(GTK_EDITABLE(entry),0,-1);//获取子窗口信息
    gtk_label_set_text(GTK_LABEL(label),text);  //打印主窗口lable信息
    gtk_entry_set_text(GTK_ENTRY(shuru),text);  //打印信息    
}

void delete_event()  //实现隐藏函数
{
    gtk_widget_hide_all(window_test);
}

GtkWidget *create_main_window()  //实现主窗口
{  
    GtkWidget *window;  
    GtkWidget *vbox;  
    GtkWidget *test_button;  

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);  //创建子窗口
    gtk_window_set_title(GTK_WINDOW(window), "DEMO");  
  
    vbox = gtk_vbox_new(FALSE, 0);  
    gtk_container_add(GTK_CONTAINER(window), vbox);  
  
    test_button=gtk_button_new_with_label("打开新窗口");  
    gtk_container_add(GTK_CONTAINER(vbox), test_button);  
  
    label = gtk_label_new("接受窗口Entry的输入内容");  
    gtk_container_add(GTK_CONTAINER(vbox), label);  
  
    shuru=gtk_entry_new();//新建 输入框
    gtk_container_add(GTK_CONTAINER(vbox), shuru);  

    void show_test_window(GtkWidget *widget,gpointer data)  
    {
        gtk_widget_show_all(window_test);
    }  
  
    g_signal_connect_swapped(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit), NULL);  
  
    g_signal_connect(G_OBJECT(test_button), "clicked",G_CALLBACK(show_test_window), NULL);  
  
    return window;  
}  
  
GtkWidget *create_test_window() //实现子窗口 
{  
    GtkWidget *vbox;  
    GtkWidget *button;  
  
    window_test = gtk_window_new(GTK_WINDOW_TOPLEVEL);  
  
    vbox = gtk_vbox_new(FALSE, 0);  
    gtk_container_add(GTK_CONTAINER(window_test), vbox);  
  
    button=gtk_button_new_with_label("点击改变主窗口标签文字");  //按钮
    gtk_container_add(GTK_CONTAINER(vbox), button);  
  
    entry=gtk_entry_new();  //输入框
    gtk_entry_set_text(GTK_ENTRY(entry),"Hello World");  //输入框默认文字
    gtk_container_add(GTK_CONTAINER(vbox), entry);  	//
    g_signal_connect(G_OBJECT(window_test),"delete_event",G_CALLBACK(delete_event), NULL);  //调用隐藏函数
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(change_label_text), NULL);  
  
    return window_test;  
}  
  
int main( int argc, char *argv[])  
{  
    GtkWidget *window_main=NULL;  
  
    gtk_init(&argc, &argv);  
  
    window_main=create_main_window();  //调用主窗口
    window_test=create_test_window();  //调用子窗口
  
    gtk_widget_show_all(window_main);  
    gtk_main();  
  
    return 0;  
}  
