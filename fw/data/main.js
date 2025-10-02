
var statusTab = document.getElementById("status-tab");
var batteryTab = document.getElementById("battery-tab");
var driveTab = document.getElementById("drive-tab");
var chargeTab = document.getElementById("charge-tab");
var accessoriesTab = document.getElementById("accessories-tab");

var ui = {
    onLoad: function() {
        batteryTab.classList.add("hidden");
        driveTab.classList.add("hidden");
        chargeTab.classList.add("hidden");
        accessoriesTab.classList.add("hidden");
    }
}

function showTab(tabId, buttonId) {
    var contentContainers = document.querySelectorAll('.tab');
    contentContainers.forEach(function(item) {
        item.classList.add('hidden');
    });
    var tab = document.getElementById(tabId);
    tab.classList.remove('hidden');
    document.querySelectorAll('.nav-button').forEach(function(item) {
        item.classList.remove('nav-active');
    });
    document.getElementById(buttonId).classList.add('nav-active');
}

function showBatteryTab(tabId, buttonId) {
    // Switch the tab
    var batteryTabs = document.querySelectorAll('.battery-subtab');
    batteryTabs.forEach(function(item) {
        console.log("Hiding " + item);
        item.classList.add('hidden');
    });
    var tab = document.getElementById(tabId);
    tab.classList.remove('hidden');
    // Update the active button
    document.querySelectorAll('.battery-nav-button').forEach(function(item) {
        item.classList.remove('battery-nav-active');
    });
    document.getElementById(buttonId).classList.add('battery-nav-active');
}

function showPackTab (tabId, buttonId) {
    // Hide all tabs
    document.querySelectorAll('.pack-tab').forEach(function(item) {
        item.classList.add('hidden');
    });
    // Show the new active tab
    var tab = document.getElementById(tabId);
    tab.classList.remove('hidden');
    // Update the active button
    document.querySelectorAll('.pack-nav-button').forEach(function(item) {
        item.classList.remove('pack-nav-active');
    });
    document.getElementById(buttonId).classList.add('pack-nav-active');
}

function showVoltagesTempsTab (tabId, buttonId) {
    console.log("Showing " + tabId);
    // Hide all tabs
    document.querySelectorAll('.pack-tab').forEach(function(item) {
        item.classList.add('hidden');
    });
    // Show the new active tab
    var tab = document.getElementById(tabId);
    tab.classList.remove('hidden');
    // Update the active button
    document.querySelectorAll('.voltage-temperature-nav-button').forEach(function(item) {
        item.classList.remove('voltage-temperature-nav-active');
    });
    document.getElementById(buttonId).classList.add('voltage-temperature-nav-active');
}

function showChargeTab(tabId, buttonId) {
    var chargeTabs = document.querySelectorAll('.charge-tab');
    chargeTabs.forEach(function(item) {
        item.classList.add('hidden');
    });
    var tab = document.getElementById(tabId);
    tab.classList.remove('hidden');
    document.querySelectorAll('.charge-nav-button').forEach(function(item) {
        item.classList.remove('charge-nav-active');
    });
    document.getElementById(buttonId).classList.add('charge-nav-active');
}

// function showVoltageTemperatureTab(){

// }

const statuses = [ "status-standby", "status-drive", "status-charge", "status-overheat", "status-empty" ];
let statusCounter = 0;
let chargeCounter = 0;
var statusInterval = window.setInterval(function() {
    // rotate status
    document.querySelectorAll('.status-title').forEach(function(item) {
        item.classList.add('hidden');
    });
    document.getElementById(statuses[statusCounter]).classList.remove('hidden');
    statusCounter += 1;
    if (statusCounter >= statuses.length) {
        statusCounter = 0;
    }
    // charge progress
    document.getElementById('charge-progress-bar').style.width = "" + chargeCounter + "%";
    document.getElementById('charge-progress-bar').innerHTML = "<p>" + chargeCounter + "%</p>";
    chargeCounter += 10;
    if ( chargeCounter > 100 ) {
        chargeCounter = 0;
    }
}, 2000);

window.addEventListener('click', function(event) {
    let id = event.target.id;
    // Main tabs
    if (id === "status-tab") {
        showTab("status-content", "status-tab");
    } else if (id === "battery-tab") {
        showTab("battery-content", "battery-tab");
    } else if (id === "drive-tab") {
        showTab("drive-content", "drive-tab");
    } else if (id === "charge-tab") {
        showTab("charge-content", "charge-tab");
    } else if (id === "accessories-tab") {
        showTab("accessories-content", "accessories-tab");
    }
    // Battery subtabs
    else if (id === "battery-status-tab") {
        showBatteryTab('battery-status-wrapper', 'battery-status-tab');
    } else if (id === "battery-history-tab") {
        showBatteryTab('battery-history-wrapper', 'battery-history-tab')
    } else if (id === "battery-settings-tab") {
        showBatteryTab('battery-settings-wrapper', 'battery-settings-tab');
    }

    // Voltage/temperature subtabs
    else if (id === "pack1-tab") {
        if ( document.querySelector('.voltage-temperature-nav-active').id === 'voltages-tab' || document.querySelector('.voltage-temperature-nav-active').id === 'voltages-tab') {
            showPackTab('cell-voltages-front', 'pack1-tab');
        } else {
            showPackTab('cell-temperatures-front', 'pack1-tab');
        }
    } else if ( id === "pack2-tab") {
        if ( document.querySelector('.voltage-temperature-nav-active').id === 'voltages-tab' || document.querySelector('.voltage-temperature-nav-active').id === 'voltages-tab' ) {
            showPackTab('cell-voltages-rear', 'pack2-tab');
        } else {
            showPackTab('cell-temperatures-rear', 'pack2-tab');
        }
    } else if ( id === "voltages-tab" ) {
        if ( document.querySelector('.pack-nav-active').id === 'pack1-tab' ) {
            showVoltagesTempsTab('cell-voltages-front', 'voltages-tab');
        } else {
            showVoltagesTempsTab('cell-voltages-rear', 'voltages-tab');
        }
    } else if ( id === "temperatures-tab" ) {
        if ( document.querySelector('.pack-nav-active').id === 'pack1-tab' ) {
            showVoltagesTempsTab('cell-temperatures-front', 'temperatures-tab');
        } else {
            showVoltagesTempsTab('cell-temperatures-rear', 'temperatures-tab');
        }
    }

    // Charge subtabs
    else if (id === "charge-status-tab") {
        showChargeTab('charge-status-wrapper', 'charge-status-tab');
    } else if (id === "charge-settings-tab") {
        showChargeTab('charge-settings-wrapper', 'charge-settings-tab');
    }


});