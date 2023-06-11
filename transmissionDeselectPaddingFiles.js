/**
 * This function deselects all padding files in a Transmission Web Interface.
 * Open the "files" section of a torrent, and then run this function.
 */
function deselectPaddingFiles()
{
    try
    {
        var count = 0;
        var fileList = document.getElementsByClassName("inspector_torrent_file_list_entryodd");

        for(var i = 0; i != fileList.length; ++i)
        {
            var fileEntry = fileList[i];
            var fileName = fileEntry.getElementsByClassName("inspector_torrent_file_list_entry_name")[0].textContent;
            var fileCheckBox = fileEntry.getElementsByClassName("file_wanted_control")[0];
            if(
                fileName.toLowerCase().indexOf("padding_file") != -1 &&
                !fileCheckBox.hasAttribute("disabled") &&
                fileCheckBox.checked
            ){
                fileCheckBox.click();
                console.log("Deselecting " + fileName);
                ++count;
            }
        }

        console.log("Deselected " + count + " file(s)");
        alert("Deselected " + count + " file(s).\nAll HTTP requests have been sent to the server. It may take several minutes for the server to process these requests. Do not run the code again during this time");
    }
    catch(e)
    {
        console.log(e);
        alert("Operation failed!\n" + e);
    }
}
