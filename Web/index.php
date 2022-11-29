<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL); 
class Morse {
    /*
    idee: input feld für morsesignal (8 Bit) 
    -> wird gespeichert (json oder sql datenbank)
    -> nodemcu ruft aktuelle Befehle ab und morst diese an de Industrieroboter
    (Überprüfung alle 3s)
    */

    private $isRobot;

    function __construct(){
        $this->isRobot = isset($_GET["robot"]);
        if($this->isRobot){
            $this->handleRobot();
        }else if(isset($_POST["code"])){
            $this->createCode();
        }else {
            $this->handleHuman();
        }
    }

    
    /*
    output: next / newest command to run
    */
    function handleRobot(){

    }

    /*
    gui: form to create new morse code
    */
    function handleHuman(){
        ?>
        <form action="#" method="post">
            <div class="form-group">
                <label for="code">Morse Code</label>
                <input type="text" class="form-control" id="code" aria-describedby="codeHelp" placeholder="Enter code">
                <small id="codeHelp" class="form-text text-muted">Format: 8 Bits (0 or 1)</small>
            </div>
            <div class="form-group">
                <label for="exampleFormControlSelect1">Morse Number</label>
                <select class="form-control" id="exampleFormControlSelect1">
                <option>1</option>
                <option>2</option>
                <option>3</option>
                <option>4</option>
                <option>5</option>
                </select>
            </div>
            <button type="submit" class="btn btn-primary">Submit</button>
        </form>
        <?php
    }

    /*
    store sent command (json or database)
    */
    function createCode(){

    }
}

$morse = new Morse();