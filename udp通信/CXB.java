package p2p3;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.UnknownHostException;
import java.net.SocketException;
import java.net.InetAddress;
import java.net.Socket;
import java.net.ServerSocket;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.Color;
import java.awt.Font;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JTextArea;
import javax.swing.JScrollPane;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
class QQ_UDP implements ActionListener,Runnable
{
JFrame JFm = new JFrame("P2P——陈兴波： ");
JTextArea dialogArea = new JTextArea();
JScrollPane JSP = new JScrollPane(dialogArea);//为聊天区， 添加滚动 窗格,如果不是自动的换行， 就必须用滚动窗
JLabel Goal_IP_lable = new JLabel("目标IP地址： ");
JLabel Send_port_lable = new JLabel("发送端口： ");
JLabel Receive_port_lable = new JLabel("接收端口： ");
JTextField msgField,sendPortField,receivePortField,Goal_IP_Field;
JButton startJBt = new JButton("开始");
JButton sendJBt = new JButton("发送");
JPanel Jpl_North,Jpl_South;//南北面板
Thread Td = null;
DatagramPacket sendPack,receivePack;
DatagramSocket sendSocket,receiveSocket;
InetAddress goal_IP;
int sendPort,receivePort;
byte inBuf[] = new byte[1024];
byte outBuf[] = new byte[1024];
Socket ToQQClient;
 ServerSocket serverSocket;
DataInputStream inFromQQClient;
DataOutputStream outToQQClient;
public QQ_UDP()
{
dialogArea.setEditable(false);//不可编辑
dialogArea.setLineWrap(true);//自动换行
dialogArea.setBackground(Color.WHITE);
dialogArea.setFont(new Font("宋体",Font.BOLD,18));
sendPortField = new JTextField();
sendPortField.setColumns(5);
receivePortField = new JTextField();
receivePortField.setColumns(5);
Goal_IP_Field = new JTextField();
Goal_IP_Field.setColumns(8);
startJBt.addActionListener(this);
Jpl_North = new JPanel();
Jpl_North.setLayout(new FlowLayout());
Jpl_North.setBackground(Color.BLUE);
Jpl_North.add(Receive_port_lable);
Jpl_North.add(receivePortField);
Jpl_North.add(Send_port_lable);
Jpl_North.add(sendPortField);
Jpl_North.add(Goal_IP_lable);
Jpl_North.add(Goal_IP_Field);
Jpl_North.add(startJBt);
msgField = new JTextField();
msgField.setColumns(40);
msgField.setEditable(false);
msgField.addActionListener(this);
sendJBt.setEnabled(false);
sendJBt.addActionListener(this);
Jpl_South = new JPanel();
Jpl_South.setLayout(new FlowLayout());
Jpl_South.setBackground(Color.BLUE);
Jpl_South.add(msgField);
Jpl_South.add(sendJBt);
JFm.add(JSP,BorderLayout.CENTER);
JFm.add(Jpl_North,BorderLayout.NORTH);
JFm.add(Jpl_South,BorderLayout.SOUTH);
JFm.setSize(600,400);
JFm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
JFm.setVisible(true);
}
 public void actionPerformed(ActionEvent e)
{
try
{
if(e.getSource()==startJBt)//点击开始
{
sendPort = Integer.parseInt(sendPortField.getText());
goal_IP = InetAddress.getByName(Goal_IP_Field.getText());
sendSocket = new DatagramSocket();//构造数据报套接字并将其绑定到本地主机上任何可用的端口。
receivePort = Integer.parseInt(receivePortField.getText());
receivePack = new DatagramPacket(inBuf,1024);//接收长度为 length 的数据包
receiveSocket = new DatagramSocket(receivePort);//创建数据报套接字并将其绑定到本地主机上的指定端口。
Td = new Thread(this);
Td.setPriority(Thread.MIN_PRIORITY);
Td.start();
startJBt.setEnabled(false);
sendJBt.setEnabled(true);
msgField.setEditable(true);
}
else//点击发送或者 按回车
{
outBuf = msgField.getText().getBytes();
sendPack = new
DatagramPacket(outBuf,outBuf.length,goal_IP,sendPort);
//用来将长度为 length 的包发送到指定主机上的指定端口号
sendSocket.send(sendPack);
dialogArea.append("我： "+msgField.getText()+"\n");
msgField.setText(null);
}
}
catch(UnknownHostException UE)
{
dialogArea.append("无法连接到指定地址\n");
}
catch(SocketException SE)
{
dialogArea.append("无法打开指定端口\n");
}
catch(IOException IE)
{
dialogArea.append("发送数据失败\n");
 }
catch(Exception E)
{
dialogArea.append("端口初始化失败\n");
}
}
public void run()
{
String St;
while(true)
{
try
{
receiveSocket.receive(receivePack);//接受数据
St = new String(receivePack.getData(),0,receivePack.getLength());
dialogArea.append(Goal_IP_Field.getText()+":"+St+"\n");
Thread.sleep(1000);
}
catch(IOException IE)
{
dialogArea.append("接收数据出错");
}
catch(Exception e)
{
dialogArea.append("线程出错： "+e);
}
}
}
}
public class CXB
{
public static void main(String args[])
{
new QQ_UDP();
}
}