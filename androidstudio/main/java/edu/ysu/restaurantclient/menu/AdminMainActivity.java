package edu.ysu.restaurantclient.menu;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.firebase.firestore.FirebaseFirestore;

import java.util.HashMap;

import edu.ysu.restaurantclient.R;

public class AdminMainActivity extends AppCompatActivity {

    FirebaseFirestore dataBase = FirebaseFirestore.getInstance();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_admin_main);

        EditText itemName = findViewById(R.id.itemName);
        EditText itemNum = findViewById(R.id.itemNum);
        EditText itemPrice = findViewById(R.id.itemPrice);

        Button addItem = this.findViewById(R.id.addButton);
        addItem.setOnClickListener(v -> {
            int itemNumber = Integer.parseInt(itemNum.getText().toString());
            String item = itemName.getText().toString();
            String price = itemPrice.getText().toString();

            String itemNumberString = Integer.toString(itemNumber);

            Item itemObj = new Item(item, price, itemNumber);

            /*HashMap hashMap = new HashMap();
            hashMap.put("ID", itemNumber);
            hashMap.put("Item Name", item);
            hashMap.put("Price", price);*/

            dataBase.collection("Items").document(itemNumberString).set(itemObj).
                addOnSuccessListener(new OnSuccessListener() {
                    @Override
                    public void onSuccess(Object o) {
                        itemName.setText(null);
                        itemNum.setText(null);
                        itemPrice.setText(null);
                        Toast.makeText(AdminMainActivity.this, "Data Saved", Toast.LENGTH_SHORT).show();
                    }
                }).addOnFailureListener(new OnFailureListener() {
                @Override
                public void onFailure(@NonNull Exception e) {
                    Toast.makeText(AdminMainActivity.this, e.toString(), Toast.LENGTH_SHORT).show();
                }
            });
        });

        Button removeItem = this.findViewById(R.id.removeButton);
        EditText removeItemNum = findViewById(R.id.removeItemNum);

        removeItem.setOnClickListener(v -> {

            int removeNum = Integer.parseInt(removeItemNum.getText().toString());

            String removeItemNumberString = Integer.toString(removeNum);

            dataBase.collection("Items").document(removeItemNumberString).delete().
                    addOnSuccessListener(new OnSuccessListener() {
                        @Override
                        public void onSuccess(Object o) {
                            removeItemNum.setText(null);
                            Toast.makeText(AdminMainActivity.this, "Data Deleted", Toast.LENGTH_SHORT).show();
                        }
                    }).addOnFailureListener(new OnFailureListener() {
                @Override
                public void onFailure(@NonNull Exception e) {
                    Toast.makeText(AdminMainActivity.this, e.toString(), Toast.LENGTH_SHORT).show();
                }
            });
        });
    }
}