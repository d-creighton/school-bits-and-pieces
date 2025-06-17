package edu.ysu.restaurantclient.menu;

import java.util.HashMap;
import java.util.Map;

public class Item {
    private int itemNum;
    private String item;
    private String price;


    public Item() {
        //Firestore needs an empty public constructor to operate, i dont know why
    }

    public Item(String item, String price, int itemNum) {
        this.itemNum = itemNum;
        this.item = item;
        this.price = price;
    }


    public void setItemNum(int itemNum) {
        this.itemNum = itemNum;
    }

    public void setItem(String item) {
        this.item = item;
    }

    public void setPrice(String price) {
        this.price = price;
    }

    public int getItemNum() {
        return itemNum;
    }

    public String getItem() {
        return item;
    }

    public String getPrice() {
        return price;
    }

}
