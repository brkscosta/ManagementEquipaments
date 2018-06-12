
/*
 *
 * @author brkscosta
 *
 */
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class FirstScreen extends Parent {


    public void seeContent(Stage stage) {

        stage.setTitle("Olaa");
        Button buttonBack = new Button();

        buttonBack.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {

            }
        });

        StackPane root = new StackPane();
        root.getChildren().add(buttonBack);
        stage.setScene(new Scene(root, 500, 500));
        stage.show();


    }


    @Override
    public Node getStyleableNode() {
        return null;
    }
}
