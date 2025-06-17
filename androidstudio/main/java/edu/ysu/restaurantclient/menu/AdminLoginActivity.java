package edu.ysu.restaurantclient.menu;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import java.math.BigInteger;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import edu.ysu.restaurantclient.R;

public class AdminLoginActivity extends AppCompatActivity {
    String loginPassword = "password";
    String loginUsername = "restaurantclienttest@gmail.com";
    String hashedPw="";
    String hashedUser="";
    String hashedUserIn="";
    String hashedPwIn="";
    boolean username=false;
    boolean password=false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_admin_login);

        EditText email = findViewById(R.id.email);
        EditText password = findViewById(R.id.password);
        Button loginB = this.findViewById(R.id.loginButton);
        loginB.setOnClickListener(v -> {
            try {
                 hashedPw=toHexString(getSHA(loginPassword));
                hashedUser=toHexString(getSHA(loginUsername));

                hashedUserIn=toHexString(getSHA(email.getText().toString()));
                hashedPwIn=toHexString(getSHA(password.getText().toString()));


                //  email and pass into database by calling email.getText().toString() and pass.getText().toString()
            } catch (NoSuchAlgorithmException e) {
                e.printStackTrace();
            }
            if(hashedPw.equals(hashedPwIn) && hashedUser.equals(hashedUserIn)){
                Intent intent = new Intent(this, AdminMainActivity.class);
                startActivity(intent);
            }
        });
    }
            //  email and pass into database by calling email.getText().toString() and pass.getText().toString()

            public void goToAdminMain (View view){
                Intent intent = new Intent(this, AdminMainActivity.class);
                startActivity(intent);
            }

            public static byte[] getSHA (String input) throws NoSuchAlgorithmException
            {
                // Static getInstance method is called with hashing SHA
                MessageDigest md = MessageDigest.getInstance("SHA-256");

                // digest() method called
                // to calculate message digest of an input
                // and return array of byte
                return md.digest(input.getBytes(StandardCharsets.UTF_8));
            }


            public static String toHexString ( byte[] hash)
            {
                // Convert byte array into signum representation
                BigInteger number = new BigInteger(1, hash);

                // Convert message digest into hex value
                StringBuilder hexString = new StringBuilder(number.toString(16));

                // Pad with leading zeros
                while (hexString.length() < 32) {
                    hexString.insert(0, '0');
                }

                return hexString.toString();
            }



        }