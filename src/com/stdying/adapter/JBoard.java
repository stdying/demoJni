package com.stdying.adapter;
/**
 * 在Java中保存使用int保存JNI中的一个指针对象,参考 http://grdurand.com/java/jni.html
 * */
import java.awt.*;
import java.awt.event.*;

class JBoard {
    private int cBoard = 0;
    private JBoardGUI gui;

    JBoard (int cBrd) {
        cBoard = cBrd;
        gui = new JBoardGUI(this);
    }
        
    native void setLength(int cBoard, int len);
    native int  getLength(int cBoard);

    void setLength(int len) {
        setLength(cBoard, len);
    }
    int getLength() {
        return getLength(cBoard);
    }

    public void levelChanged(int lev) {
        gui.setLevel(lev); 
    }
}

class JBoardGUI extends Frame {
    JBoard    jBoard;

    TextField levelText;
    TextField lengthText;
    Scrollbar lengthSB;

    JBoardGUI (JBoard jBrd) {
        super("JBoard");
        jBoard = jBrd;
        setUpUI();
    }

    void setLevel(int lev) {
        levelText.setText(Integer.toString(lev));
    }
    
    private void setUpUI() {
        levelText  = new TextField(Integer.toString(0), 5);
        lengthSB   = new Scrollbar(Scrollbar.HORIZONTAL, jBoard.getLength(), 1, 0, 26);
        lengthText = new TextField(Integer.toString(lengthSB.getValue()), 5);

        lengthSB.addAdjustmentListener(new AdjustmentListener() {
            public void adjustmentValueChanged(AdjustmentEvent e) {
                int len = lengthSB.getValue();
                lengthText.setText(Integer.toString(len));
                jBoard.setLength(len);
            }
        });

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        setSize(150, 100);
        setLayout(new FlowLayout());
        
        Panel p = new Panel(new FlowLayout());
        
        p.add(levelText);
        p.add(lengthText);
        p.setEnabled(false);

        add(p);
        add(lengthSB);

        validate();
        setVisible(true);
    }
}

