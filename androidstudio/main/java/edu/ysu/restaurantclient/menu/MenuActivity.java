package edu.ysu.restaurantclient.menu;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.firebase.ui.firestore.FirestoreRecyclerOptions;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.firebase.firestore.CollectionReference;
import com.google.firebase.firestore.EventListener;
import com.google.firebase.firestore.FirebaseFirestore;
import com.google.firebase.firestore.FirebaseFirestoreException;
import com.google.firebase.firestore.QueryDocumentSnapshot;
import com.google.firebase.firestore.QuerySnapshot;

import edu.ysu.restaurantclient.R;

public class MenuActivity extends AppCompatActivity {

    FirebaseFirestore dataBase = FirebaseFirestore.getInstance();

    CollectionReference reference = dataBase.collection("Items");
    TextView menuView;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);

        menuView = findViewById(R.id.menu_view);

        loadData();
    }

    @Override
    protected void onStart() {
        super.onStart();
        reference.addSnapshotListener(this, new EventListener<QuerySnapshot>() {
            @Override
            public void onEvent(@Nullable QuerySnapshot queryDocumentSnapshots, @Nullable FirebaseFirestoreException e) {
                if (e != null) {
                    return;
                }

                String itemData = "";

                for (QueryDocumentSnapshot documentSnapshot : queryDocumentSnapshots) {
                    Item itemObj = documentSnapshot.toObject(Item.class);

                    String itemName = itemObj.getItem();
                    String itemPrice = itemObj.getPrice();
                    int itemNum = itemObj.getItemNum();

                    itemData += "Item Name: " + itemName + "\nPrice: $" + itemPrice + "\nItem Number: " + itemNum + "\n\n";
                }

                menuView.setText(itemData);
            }
        });
    }

    public void goToAdminLogin(View view) {
        Intent intent = new Intent(this, AdminLoginActivity.class);
        startActivity(intent);
    }

    public void loadData () {
        reference.get().addOnSuccessListener(new OnSuccessListener<QuerySnapshot>() {
            @Override
            public void onSuccess(QuerySnapshot queryDocumentSnapshots) {
                String itemData = "";

                for (QueryDocumentSnapshot documentSnapshot : queryDocumentSnapshots) {
                    Item itemObj = documentSnapshot.toObject(Item.class);

                    String itemName = itemObj.getItem();
                    String itemPrice = itemObj.getPrice();
                    int itemNum = itemObj.getItemNum();

                    itemData += "Item Name: " + itemName + "\nPrice: $" + itemPrice + "\nItem Number: " + itemNum + "\n\n";

                }

                menuView.setText(itemData);
            }
        });
    }
}