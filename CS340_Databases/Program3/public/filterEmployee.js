function filterEmployeeByProject() {
    //get the id of the selected homeworld from the filter dropdown
    var project_pno = document.getElementById('project_filter').value
    //construct the URL and redirect to it
    window.location = '/employee/filter/' + parseInt(project_pno)
}
