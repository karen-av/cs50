
<!DOCTYPE html>

<html>
    <head>
        <title>Main page</title>
    </head>
    <body>
        <form action = "action.php" metoth = "post">
            <p> Your name: <input type = "text" name = "name"/></p>
            <p> Your age: <input type = "text" name = "age" /></p>
            <p> <input type = "submit"  value = "Давай"> </p>
        </form>

        Hi <?php echo htmlspecialchars($_POST['name']); ?>
        Your are <?php echo (int)$_POST [ 'age']; ?> Years old.
    </body>
</html>

