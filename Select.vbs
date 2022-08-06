Dim pInput
pInput = InputBox("Select plant by typing the number:" & Chr(13) & Chr(10) & "1. Demo." & Chr(13) & Chr(10) & "2. Cactus." & Chr(13) & Chr(10) & "3. Snakeplant." & Chr(13) & Chr(10) & "4. Rose." & Chr(13) & Chr(10) & "5. Aloevera.")
If pInput = "2" Then
msgbox "You entered: Cactus"
ElseIf pInput = "3" Then
CreateObject("WScript.Shell").Run("""D:\BPPIMT Notes and assignments\Workshops, Courses, Projects\Forma 2022\Plant Monitoring System\Sketches\Snakeplant\Snakeplant.ino""")
ElseIf pInput = "4" Then
msgbox "You entered: Rose"
ElseIf pInput = "5" Then
msgbox "You entered: Aloevera"
ElseIf pInput = "1" Then
CreateObject("WScript.Shell").Run("""D:\BPPIMT Notes and assignments\Workshops, Courses, Projects\Forma 2022\Plant Monitoring System\Sketches\Demonstration\Demonstration.ino""")
ElseIf pInput = "" Then
Wscript.Quit
Else
msgbox "Nope."
End If
