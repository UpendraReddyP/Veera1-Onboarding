<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>HR Staff Management Dashboard</title>
  <style>
    /* FULL CSS from your version — no changes needed */
    :root {
        --primary-color: #2c3e50;
        --secondary-color: #3498db;
        --background-color: #f5f6fa;
        --card-background: #ffffff;
        --text-color: #2c3e50;
        --border-radius: 12px;
        --shadow-light: 0 5px 15px rgba(0, 0, 0, 0.1);
        --shadow-hover: 0 8px 25px rgba(0, 0, 0, 0.15);
    }

    * {
        margin: 0;
        padding: 0;
        box-sizing: border-box;
    }

    body {
        font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        background: var(--background-color);
        color: var(--text-color);
        line-height: 1.6;
    }

    .container {
        max-width: 1400px;
        margin: 0 auto;
        padding: 20px;
    }

    header {
        background: linear-gradient(135deg, var(--primary-color), var(--secondary-color));
        padding: 20px;
        border-radius: var(--border-radius);
        margin-bottom: 30px;
        animation: slideDown 0.5s ease-out;
    }

    @keyframes slideDown {
        from { transform: translateY(-100%); opacity: 0; }
        to { transform: translateY(0); opacity: 1; }
    }

    header h1 {
        color: white;
        text-align: center;
        font-size: 2.2em;
        margin-bottom: 10px;
    }

    .search-bar {
        max-width: 400px;
        margin-right: auto;
    }

    .search-bar input {
        width: 100%;
        padding: 12px 20px;
        border: none;
        border-radius: 25px;
        font-size: 16px;
        box-shadow: var(--shadow-light);
        transition: all 0.3s ease;
    }

    .search-bar input:focus {
        outline: none;
        box-shadow: var(--shadow-hover);
    }

    .employee-grid {
        display: grid;
        grid-template-columns: repeat(auto-fill, minmax(300px, 1fr));
        gap: 25px;
        padding: 20px 0;
    }

    .employee-card {
        background: var(--card-background);
        border-radius: var(--border-radius);
        box-shadow: var(--shadow-light);
        overflow: hidden;
        transition: transform 0.3s ease, box-shadow 0.3s ease;
        animation: fadeIn 0.5s ease-out forwards;
        opacity: 0;
        word-break: break-word;
        word-spacing: 0.3em;
    }

    @keyframes fadeIn {
        from { opacity: 0; transform: translateY(20px); }
        to { opacity: 1; transform: translateY(0); }
    }

    .employee-card:hover {
        transform: translateY(-5px);
        box-shadow: var(--shadow-hover);
    }

    .card-header {
        background: linear-gradient(135deg, var(--secondary-color), #2980b9);
        color: white;
        padding: 20px;
        display: flex;
        align-items: center;
        gap: 15px;
    }

    .profile-pic {
        width: 90px;
        height: 100px;
        border-radius: 50%;
        object-fit: cover;
        border: 2px solid white;
    }

    .info-container {
        flex: 1;
        display: flex;
        flex-direction: column;
        justify-content: center;
    }

    .card-header h2 {
        font-size: 1.5em;
        margin: 0;
        word-spacing: 0.3em;
    }

    .emp-id {
        font-size: 0.9em;
        opacity: 0.9;
        margin-top: 5px;
    }

    .card-body {
        padding: 20px;
    }

    .info-group {
        display: grid;
        grid-template-columns: 1fr 1.2fr;
        margin-bottom: 12px;
    }

    .info-group label {
        color: #7f8c8d;
        font-weight: 500;
    }

    .info-group span {
        color: var(--text-color);
    }

    .card-footer {
        padding: 15px 20px;
        border-top: 1px solid #eee;
        text-align: center;
    }

    .btn-view {
        width: 100%;
        background: var(--secondary-color);
        color: white;
        border: none;
        padding: 10px 25px;
        border-radius: 25px;
        cursor: pointer;
        font-weight: 500;
        transition: all 0.3s ease;
    }

    .btn-view:hover {
        background: #2980b9;
        transform: translateY(-2px);
    }

    .modal {
        display: none;
        position: fixed;
        top: 0;
        left: 0;
        width: 100%;
        height: 100%;
        background-color: rgba(0, 0, 0, 0.5);
        z-index: 1000;
    }

    .modal-content {
        position: relative;
        background-color: #fff;
        margin: 2% auto;
        padding: 0;
        width: 90%;
        max-width: 800px;
        max-height: 85vh;
        border-radius: 15px;
        overflow-y: auto;
    }

    .modal-header {
        background: linear-gradient(135deg, var(--secondary-color), #2980b9);
        color: white;
        padding: 20px;
        display: flex;
        align-items: center;
        gap: 15px;
    }

    .modal-header h2 {
        font-size: 1.8em;
        margin: 0;
    }

    .close-modal {
        position: absolute;
        right: 20px;
        top: 20px;
        font-size: 28px;
        color: white;
        cursor: pointer;
    }

    .modal-body {
        padding: 30px;
    }

    .details-section {
        margin-bottom: 30px;
        background: #f8f9fa;
        padding: 20px;
        border-radius: 10px;
    }

    .details-grid {
        display: grid;
        grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
        gap: 20px;
    }

    .detail-item label {
        color: #7f8c8d;
        font-weight: 500;
        font-size: 0.9em;
    }

    .detail-item span {
        color: var(--text-color);
        font-weight: 500;
        word-break: break-word;
    }

    @media (max-width: 768px) {
        .employee-grid {
            grid-template-columns: 1fr;
        }

        .modal-content {
            max-height: 95vh;
            margin: 1% auto;
            width: 98%;
        }

        .details-grid {
            grid-template-columns: 1fr;
        }
    }
  </style>
</head>
<body>
  <div class="container">
    <header>
      <h1>HR Staff Management</h1>
      <p style="color: #fffcfc; text-align: center;">"Individuals play the game, but teams beat the odds."</p>
    </header>
    <div class="search-bar">
      <input type="text" id="searchInput" placeholder="Search employees by name, department, or employee ID...">
    </div>
    <main class="employee-grid" id="dataContainer"></main>
  </div>

  <!-- ✅ MODAL (working) -->
  <div id="modal" class="modal">
    <div class="modal-content">
      <div class="modal-header">
        <img id="modalProfilePic" class="profile-pic" src="" alt="Profile Picture"
             onerror="this.src='https://via.placeholder.com/50'; this.alt='No Profile Picture'">
        <div class="info-container">
          <h2 id="modalHeader">Employee Name</h2>
          <span id="modalEmpId" class="emp-id"></span>
        </div>
        <div class="close-modal" onclick="hideModal()">×</div>
      </div>
      <div class="modal-body" id="modalBody"></div>
    </div>
  </div>

  <script>
    function formatDate(dateString) {
      if (!dateString) return 'N/A';
      const date = new Date(dateString);
      return date.toLocaleDateString('en-US', { year: 'numeric', month: 'long', day: 'numeric' });
    }

    async function fetchActiveEmployees() {
      try {
        const response = await fetch('http://16.171.19.248:3068/api/employees/active');
        const data = await response.json();
        renderEmployeeCards(data.data);
      } catch (err) {
        document.getElementById('dataContainer').innerHTML = `<p style="color:red;">Failed to fetch data</p>`;
      }
    }

    function renderEmployeeCards(employees) {
      const container = document.getElementById('dataContainer');
      container.innerHTML = '';
      employees.forEach(emp => {
        const card = document.createElement('div');
        card.className = 'employee-card';
        card.innerHTML = `
          <div class="card-header">
            <img class="profile-pic" src="http://16.171.19.248:3068/api/onboarding/${emp.id}/file/profilePic"
                 onerror="this.src='https://via.placeholder.com/50'">
            <div class="info-container">
              <h2>${emp.full_name}</h2>
              <span class="emp-id">${emp.emp_id || 'N/A'}</span>
            </div>
          </div>
          <div class="card-body">
            <div class="info-group"><label>Department:</label><span>${emp.department || 'N/A'}</span></div>
            <div class="info-group"><label>Position:</label><span>${emp.job_role || 'N/A'}</span></div>
            <div class="info-group"><label>Join Date:</label><span>${formatDate(emp.job_start_date)}</span></div>
            <div class="info-group"><label>Status:</label><span>${emp.status || 'N/A'}</span></div>
          </div>
          <div class="card-footer">
            <button class="btn-view" onclick="showEmployeeDetails('${emp.id}')">View Details</button>
          </div>
        `;
        container.appendChild(card);
      });
    }

    async function showEmployeeDetails(id) {
      const response = await fetch(`http://16.171.19.248:3068/api/onboarding/${id}`);
      const emp = await response.json();
      document.getElementById('modalHeader').textContent = emp.full_name;
      document.getElementById('modalEmpId').textContent = emp.emp_id || 'N/A';
      document.getElementById('modalProfilePic').src = `http://16.171.19.248:3068/api/onboarding/${id}/file/profilePic`;
      document.getElementById('modalBody').innerHTML = `
        <div class="details-section">
          <h3>Contact Details</h3>
          <div class="details-grid">
            <div class="detail-item"><label>Email:</label><span>${emp.email || 'N/A'}</span></div>
            <div class="detail-item"><label>Phone:</label><span>${emp.phone || 'N/A'}</span></div>
            <div class="detail-item"><label>City:</label><span>${emp.city || 'N/A'}</span></div>
          </div>
        </div>
      `;
      document.getElementById('modal').style.display = 'block';
    }

    function hideModal() {
      document.getElementById('modal').style.display = 'none';
    }

    document.addEventListener('DOMContentLoaded', fetchActiveEmployees);
  </script>
</body>
</html>
