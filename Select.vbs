Dim pInput
pInput = InputBox("Select plant by typing the number:" & Chr(13) & Chr(10) & "1. Demo." & Chr(13) & Chr(10) & "2. Cactus and other xerophytes." & Chr(13) & Chr(10) & "3. Snakeplant and other moderate condition plants." & Chr(13) & Chr(10) & "4. Rose and other shrubs." & Chr(13) & Chr(10) & "5. Lily and other water loving plants.")
If pInput = "2" Then
CreateObject("WScript.Shell").Run("""Path""")
ElseIf pInput = "3" Then
CreateObject("WScript.Shell").Run("""Path""")
ElseIf pInput = "4" Then
CreateObject("WScript.Shell").Run("""Patho""")
ElseIf pInput = "5" Then
CreateObject("WScript.Shell").Run("""Path""")
ElseIf pInput = "1" Then
CreateObject("WScript.Shell").Run("""Path""")
ElseIf pInput = "" Then
Wscript.Quit
Else
msgbox "Error: Not in list."
End If
